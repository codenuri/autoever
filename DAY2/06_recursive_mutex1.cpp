#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

// C++ mutex 는 6개 입니다.             
// mutex,       recursive_mutex,       shared_mutex(C++17)
// timed_mutex, timed_recursive_mutex, timed_shared_mutex(C++17)


// std::mutex m; // 소유자라도 한번만 lock 가능합니다.
   
std::recursive_mutex m; // 뮤텍스 소유자는 여러번 lock 가능
                        // 단, lock() 횟수 만큼 unlock()해야
                        // 합니다.
int share_data = 0;

void foo()
{
    m.lock();
    m.lock(); // 뮤텍스 소유자가 다시 한번 lock ?

    share_data = 100;
    std::cout << "using share_data" << std::endl;
    
    m.unlock();
    m.unlock();
}
int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}




