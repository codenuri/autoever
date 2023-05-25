#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;
#include <condition_variable>

std::condition_variable cv;


std::mutex m;
int shared_data = -1;

// 아래 코드 문제점
// 1. 소비자가 늦게 도착합니다.
// 2. 생산자가 신호를 줄때 소지는 wait() 상태가 아닙니다.
// 3. 소비자가 늦게 도착해서 wait 하는데, 이 후에 신호를 주는 경우가 없습니다.

// ===> 해결책은 다음 소스

void consumer()
{
    std::this_thread::sleep_for(10ms);

    std::unique_lock<std::mutex> ul(m);

    cv.wait(ul);    

    std::cout << "consume : " << shared_data << std::endl;
}

void producer()
{
//  std::this_thread::sleep_for(10ms);
    {
        std::lock_guard<std::mutex> lg(m);
        shared_data = 100;
        std::cout << "produce : " << shared_data << std::endl;
    }

    cv.notify_one();
}


int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}