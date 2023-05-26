#include <iostream>
#include <thread>
#include <atomic>

// long x = 0;
std::atomic<long> x = 0; // 멀티 스레드에 안전하게 사용가능한
                         // 전역변수
void foo()
{
    for (int i = 0; i < 100000; ++i)
    {
        // x.fetch_add(1); // CPU lock 으로 안전하게 1증가
        // x.fetch_add(2);
        // ++x; // x.operator++() 호출, x.fetch_add(1)수행

        x.fetch_add(1, std::memory_order_relaxed);
                // ++x 와 동일한 결과 지만
                // 상황에 따라 ++x 보다 약간 빠를수 있습니다.
    }
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    std::thread t3(foo);
    t1.join();
    t2.join();
    t3.join();
    std::cout << x << std::endl;
}
