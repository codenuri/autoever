#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

std::mutex m;

void foo()
{
    // lock_guard 사용법
    // 
    // 방법 1. 생성자에서 m.lock() 수행
    {
        std::lock_guard<std::mutex> g(m);
    }

    // 방법 2. 
    if (m.try_lock())
    {
        // m 에 대해서 이미 lock 을 했지만, unlock 을 소멸자에 의존하고싶다.
        // std::lock_guard<std::mutex> g(m); // 버그, 생성자에서 lock

        std::lock_guard<std::mutex> g(m, std::adopt_lock); // ok
                        // => 생성자에서 lock 하지 말라(이미 lock 되었다)
                        // => 소멸자 unlock 기능만 사용

        // ..... 

        m.unlock();
    }
    else
    {
        //....
    }
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}



