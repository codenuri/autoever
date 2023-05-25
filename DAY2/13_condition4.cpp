#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;
#include <condition_variable>

// 1. condition_variable은 보통 flag 변수와 같이 사용합니다.
std::condition_variable cv;

bool data_ready = false;





std::mutex m;
int shared_data = -1;


void consumer()
{
//    std::this_thread::sleep_for(10ms);

    std::unique_lock<std::mutex> ul(m);


//  cv.wait(ul); // 무조건 신호를 대기

//  cv.wait(ul, 함수); // 1. 함수실행해서 결과가 참이면 대기 안함
                      // 2. 결과가 거짓이면 ul.unlock() 하고 대기
                      // 3. 신호가 오면 1번으로 이동

    cv.wait(ul, []() { return data_ready; } );

    std::cout << "consume : " << shared_data << std::endl;
}

void producer()
{
    std::this_thread::sleep_for(10ms);
    {
        std::lock_guard<std::mutex> lg(m);
        shared_data = 100;
        std::cout << "produce : " << shared_data << std::endl;
    }

    data_ready = true;
    cv.notify_one();
}


int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}