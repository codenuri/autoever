#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

// 아래 init 은 한번만 호출됩니다.
// => 스레드가 5개라도 한번 만 호출되고..
// => 늦게 도착한 스레드는 init 호출이 종료될때를 대기 합니다.


// 1. std::once_flag 타입의 전역변수를 한개 선언
std::once_flag flag;

void init(int a, double d)
{
    std::cout << "init" << std::endl;
    std::this_thread::sleep_for(2s);
}
void foo()
{
    std::cout << "start foo" << std::endl;

    // 2. init 호출시 직접호출하지 말고 call_once() 사용
    // init(10, 3.4);     

    std::call_once(flag, init, 10, 3.4);
                // => 최초 1회만 호출됩니다.
                // => 처음 도착한 스레드에 의해서 호출되고
                // => 나중에 도착한 스레드는 init 종료시까지 대기 합니다.


    std::cout << "finish foo" << std::endl;
}


int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}



