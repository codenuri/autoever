#include <iostream>
#include <chrono>
#include <thread>
using namespace std::literals;

// this_thread 4개 함수
// 1. get_id()
// 2. sleep_for()
// 3. sleep_until()
// 4. yield()

// yield : 스레드가 자신에게 부여된 실행 시간을 포기.. 
//         다른 스레드를 실행하라고 하는 것.

// yield 를 사용한 sleep 구현
void mysleep(std::chrono::microseconds us)
{
    auto target = std::chrono::high_resolution_clock::now() + us;

    // target : 깨어나야 하는 시간

    while (std::chrono::high_resolution_clock::now() < target)
        std::this_thread::yield();
}

int main()
{
    mysleep(1s);
}