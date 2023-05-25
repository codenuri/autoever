#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

std::timed_mutex m;

int main()
{
    std::unique_lock<std::timed_mutex> u1;    // mutex 연결안됨
    std::unique_lock<std::timed_mutex> u2(m); // m 관리

//  u1 = u2;            // error. 복사는 안됨
    u1 = std::move(u2); // ok


    std::cout << u1.owns_lock() << std::endl;  // true

    if (u1) // u1.owns_lock()
        std::cout << "acquire" << std::endl;

    // 소멸자에서 자동 unlock 뿐아니라 명시적으로 unlock 도 가능
    u1.unlock();

    std::cout << u1.owns_lock() << std::endl;  

    if (u1.try_lock_for(2s))
    {
        //....
        u1.unlock();
    }

    u1.release(); // mutex 와 연결 끊기
}



