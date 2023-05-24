#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

void add(std::promise<int>&& p, int a, int b)
{
    std::this_thread::sleep_for(1s);

    // 핵심 1. set_value 는 한번만 가능합니다.
    p.set_value(a + b);
//  p.set_value(a + b); // 예외 발생

    // 여러번 전달하려면 어떻게 하나요 ?
    // => std::condition_variable 등의 도구로 직접 만들어야 합니다.

    // 핵심 2. 한개의 promise 는 한개의 스레드에만 전달해야 합니다.
    // => 여러개 스레드 공유 안됨
}

int main()
{
    std::promise<int> pm;

    // 3. promise 에서 future 는 한번만 꺼낼수 있고, 
    //    future 자체가 복사도 안됩니다.
    std::future<int> ft = pm.get_future();
//  std::future<int> ft2 = pm.get_future(); // 예외
//  std::future<int> ft2 = ft; // error. 복사 생성자가 삭제

    std::thread t(add, std::move(pm), 10, 20);
        
    // 4. get 도 한번만 사용가능합니다.
    std::cout << ft.valid() << std::endl; // true

    int ret = ft.get();
//  int ret2 = ft.get(); // 예외

    // 5. get 가능한지 확인 하려면 valid 함수 사용
    std::cout << ft.valid() << std::endl; // false

    t.join();
}



