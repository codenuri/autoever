#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std::literals;

int add(int a, int b)
{
    std::cout << "add : " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(2s);
    return a + b;
}
int main()
{
    // 1. launch option 전달 가능
    // std::launch::async : 새로운 스레드로 실행해 달라.
    // std::launch::deferred : 지연된 실행. 주스레드가 결과가 필요할때
    //                          호출(ft.get() 하는 순간 호출)
    //                          스레드 생성 안됨.

    // std::launch::async || std::launch::deferred
    // => 스레드가 있는 시스템에서는 스레드로 수행
    // => 스레드가 지원되지 않은 시스템에서는 지연된 실행
    // => 옵션 생략시 디폴트값
    std::future<int> ft = std::async( std::launch::deferred, add, 10, 20);


    std::cout << "continue main : " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(2s);

    int ret = ft.get();

    std::cout << "result : " << ret << std::endl;
}



