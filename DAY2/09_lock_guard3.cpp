#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

std::mutex m;

void foo()
{
    // lock_guard 荤侩过
    // 
    // 规过 1. 积己磊俊辑 m.lock() 荐青
    {
        std::lock_guard<std::mutex> g(m);
    }

    // 规过 2. 
    if (m.try_lock())
    {
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



