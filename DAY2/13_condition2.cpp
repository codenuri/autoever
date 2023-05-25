#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

// condition_variable 사용법
// 1. 헤더 포함
#include <condition_variable>

// 2. 전역변수 생성
std::condition_variable cv;


std::mutex m;
int shared_data = -1; 



void consumer()
{
    // 소비자는
    // 3. unique_lock 으로 mutex 획득후..
    std::unique_lock<std::mutex> ul(m);

    // 4. cv.wait()로 신호를 대기 합니다.
    cv.wait(ul);    // 1. ul.unlock() 으로 lock 을 먼저 풀고
                    // 2. cv 의 신호가 올때를 대기 합니다.
                    // 3. 신호가 오면 다시 ul.lock()으로 뮤텍스 획득후
                    // 4. 아래 줄이 실행됩니다.

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

    // 5. 생산자는 생산이 끝나면 lock 을 풀고 신호를 발생합니다.
    cv.notify_one();
}


int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}