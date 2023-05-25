#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

// std::mutex m; // 1. m.lock()        : 획득 못하면 대기
                 // 2. m.try_lock()    : 획득 못하면 false

std::timed_mutex m; // 위 2개 외에 아래 2개 가능
                    // 1. m.try_lock_for(시간)  : 시간 동안 대기
                    // 2. m.try_lock_until(시간): 시간 까지 대기

// std::timed_recursive_mutex, 
// std::timed_shared_mutex, 
int share_data = 0;

void foo()
{
    //m.lock();
    // if ( m.try_lock() )
    if (m.try_lock_for(3s))
    {
        share_data = 100;
        std::cout << "using share_data" << std::endl;
        std::this_thread::sleep_for(3s);
        m.unlock();
    }
    else
    {
        std::cout << "뮤텍스 획득 실패" << std::endl;
    }
}
int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}



