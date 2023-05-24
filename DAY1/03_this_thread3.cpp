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

// yield 함수로 포기하고 1초 이후 자동으로 실행되나요 
// => 자신의 차례가 오면 실행됩니다.
// 
// 아니면 다른 thread가 돌고있으면 실행되지 않는 케이스도 있을까요 ?
// => 우선순위가 높은 스레드가 돌고 있으면 실행되지 않을수도 있지만..
// => 대부분의 OS 는 실행되지 못하고 있는 스레드의 우선순위를 높여주는 기능이 있습니다.

// yield 함수도 OS 커널까지 들어갔다 나오는걸까요?
// => API call 되므도 커널레벨입니다.
// => 그런데, OS 에 따라다를수 있습니다.