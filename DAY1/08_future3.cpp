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


    // future는 한개만 만들수 있지만
    // shared_future 는 여러개 만들수 있습니다.
    // => 하나의 결과를 여러개 스레드에서 대기

    // 1. 먼저 future를 께내세요..
    std::future<int> ft = pm.get_future();

    // 2. future 에서 shared_future를 꺼내세요
    std::shared_future<int> sft1 = ft.share();
    std::shared_future<int> sft2 = ft.share(); // 여러개도 가능
    std::shared_future<int> sft3 = sft1;  // 복사도 가능

    std::thread t(add, std::move(pm), 10, 20);

    // shared_future 를 꺼낸 경우는 
    // => 주스레드도 future 가 아닌 shared_future를 사용해야 합니다.
    // => 다른 스레드 만들때 sft2등을 전달해도 됩니다.
    // int ret1 = ft.get();
    int ret1 = sft1.get();

    t.join();
}




