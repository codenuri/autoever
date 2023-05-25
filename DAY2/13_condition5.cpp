#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex>
#include <string>
using namespace std::literals;



std::shared_mutex m;
int share_data = 0;

//std::condition_variable cv; // unique_lock 만 사용가능
std::condition_variable_any cv; // 모든 lock management 사용가능
                                // 대부분 shared_lock 과 같이 사용
bool data_ready = false;

void Writer()
{
    while (1)
    {
        {
            std::lock_guard<std::shared_mutex> g(m);
            share_data = share_data + 1;
            std::cout << "Writer : " << share_data << std::endl;
            std::this_thread::sleep_for(1s);
        }
        data_ready = true;
//      cv.notify_one(); // 한개만 깨우가
        cv.notify_all(); // 대기 중인 스레드 모두 깨우기

        std::this_thread::sleep_for(10ms);
    }
}




void Reader(const std::string& name)
{
    while (1)
    {
        {
            std::shared_lock<std::shared_mutex> g(m);

            cv.wait(g, []() {return data_ready; });

            std::cout << "Reader(" << name << ") : " << share_data << std::endl;
            std::this_thread::sleep_for(500ms);
        }

        std::this_thread::sleep_for(10ms);
    }
}

int main()
{
    std::thread t1(Writer);
    std::thread t2(Reader, "A");
    std::thread t3(Reader, "B");
    std::thread t4(Reader, "C");
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}



