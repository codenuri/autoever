#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

std::mutex       m1, m2, m3;
std::timed_mutex tm1, tm2, tm3;

// 핵심 : unique_lock 은 기능이 많다.

int main()
{
    // 1. 생성
    std::unique_lock<std::mutex> u1;    // 뮤텍스 연결안됨
    std::unique_lock<std::mutex> u2(m1);// 생성자에서 m1.lock()                 

    std::unique_lock<std::mutex> u3(m2, std::try_to_lock);
                            // m2.try_lock()
                            // 획득 못해도 대기 안함
                            // 획득 여부는 아래 코드로 조사
    if (u3.owns_lock())
        std::cout << "acquire lock" << std::endl;
    else
        std::cout << "fail to lock" << std::endl;

    // 2. 이미 lock 을 획득한 뮤텍스의 unlock 관리
    m3.lock();
    std::unique_lock<std::mutex> u4(m3, std::adopt_lock);   


    // 3. 생성자에서 lock 하지말고, 나중에 원할때 lock 하겠다는것 
    std::unique_lock<std::timed_mutex> u5(tm1, std::defer_lock);
    auto ret = u5.try_lock_for(2s);

    // 4. time_mutex 를 위한 기능도 지원
    std::unique_lock<std::timed_mutex> u6(tm2, 2s);  // tm2.try_lock_for() 사용
    std::unique_lock<std::timed_mutex> u7(tm3, std::chrono::steady_clock::now() + 2s);
    // tm3.try_lock_until() 사용               => 인자가 time_point 이경우 
}
