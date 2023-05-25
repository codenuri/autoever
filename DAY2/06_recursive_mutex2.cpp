#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

class Machine
{
//  std::mutex m;
    std::recursive_mutex m;

    int shared_data = 0;
public:
    void f1()
    {
        m.lock();
        shared_data = 100;
        m.unlock();
    }
    void f2()
    {
        m.lock();
        shared_data = 200;
        m.unlock();
    }
    void f3()
    {
        m.lock();
        
        shared_data = 300; // 공유자원 사용중에..
        f1();              // 다른 멤버 함수 호출..
                            // 결국 2번의 lock 이 발생하게 됩니다.

        m.unlock();
    }
};


int main()
{
    Machine m;
    std::thread t1(&Machine::f1, &m);
    std::thread t2(&Machine::f2, &m);
    t1.join();
    t2.join();
}



