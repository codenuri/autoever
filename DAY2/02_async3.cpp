#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std::literals;

int add(int a, int b)
{
    std::cout << "add : " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(2s);

    std::cout << "finish add" << std::endl;
    return a + b;
}
int main()
{
    std::future<int> ft = std::async(add, 10, 20);

    // 핵심 1. ft.get() 을 하지 않으면 어떻께 될까 ?

}   // <== 1. 이순간 ft 객체가 파괴됩니다. 소멸자 호출
    // <== 2. ft.get() 을 한번도 하지 않았다면 
    //        소멸자에서 ft.get() 으로 대기 하게 됩니다.
    //        즉, 실행중인 스레드가 종료될때 까지 대기합니다.



