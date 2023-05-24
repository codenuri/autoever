#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// 예외 : 스레드 단위로 동작합니다.
// 기본적으로 "새로운 스레드가 던진 예외"는 주스레드에서 받을수 없습니다
// promise 로 전달 가능합니다.

// promise 기능
// 1. 결과값 전달
// 2. 예외의 전달

void divide(std::promise<int>&& p, int a, int b)
{
    try
    {
        if (b == 0)
        {
            throw std::runtime_error("divide by zero");
        }
        p.set_value(a / b);
    }
    catch (...)
    {
        p.set_exception( std::current_exception() );
    }
}

int main()
{
    std::promise<int> pm;
    std::future<int>  ft = pm.get_future();

//  std::thread t(divide, std::move(pm), 10, 2);
    std::thread t(divide, std::move(pm), 10, 0);

    try
    {
        int ret = ft.get();
    }
    catch (std::exception& e) // C++ 표준예외의 최상의 클래스
    {
        std::cout << "예외 발생 : " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "알수 없는 예외 발생\n";
    }
 
    t.join();
}



