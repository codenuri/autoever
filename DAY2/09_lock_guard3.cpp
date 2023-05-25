#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

std::mutex m;

void foo()
{
    m.lock();
   
    // ..... 

    m.unlock();
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}



