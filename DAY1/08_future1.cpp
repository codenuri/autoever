#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

void add(std::promise<int>&& p, int a, int b)
{
    std::this_thread::sleep_for(1s);
    p.set_value(a + b);
}

int main()
{
    std::promise<int> pm;
    std::future<int> ft = pm.get_future();

    std::thread t(add, std::move(pm), 10, 20);

    //-----------------------
    // 1. ft.get()은 결과가 나올때 까지 무한히 대기 합니다.
    // int n1 = ft.get();

    // 2. timeout 지정하려면 wait_for 로 대기 하세요
    std::future_status ret = ft.wait_for(10s);

    if (ret == std::future_status::ready)
    {
        std::cout << "set_value() 되어서 결과 있음\n";

        int n = ft.get(); // 데이타가 있으므로 대기 안함
    }
    else if (ret == std::future_status::timeout)
    {
        std::cout << "대기시간초과\n";
    }
    else if (ret == std::future_status::deferred)
    {
        std::cout << "스레드 실행안됨\n";
         // => std::async() 사용시에만 나올수 있는값
         // => std::thread 로 스레드 생성시는 이값이 나오지 않음
    }

    t.join();
}



