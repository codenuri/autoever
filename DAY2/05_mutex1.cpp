#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>
using namespace std::literals;

void delay() { std::this_thread::sleep_for(20ms); }





std::mutex m;

void foo(const std::string& name)
{
//    int x = 0; // 지역변수, 스택 사용, 스레드별로 따로 생성됨.
    static int x = 0;

    for (int i = 0; i < 10; i++)
    {
        // 임계영역(critical section) : 한개 스레드만 실행하는 영역
        // 직렬화(serialization) 이라고도 합니다.
        m.lock();
        //---------------------------------
        x = 100;   delay();
        x = x + 1; delay();
        std::cout << name << " : " << x << std::endl; delay();
        //---------------------------------
        m.unlock();
    }
}





int main()
{
    std::thread t1(foo, "A");
    std::thread t2(foo, "\tB");
    t1.join();
    t2.join();
}



