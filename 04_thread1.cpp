#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

void foo()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "foo : " << i << std::endl;
        std::this_thread::sleep_for(100ms);
    }
}
int main()
{
//  foo(); // 주스레드가 그냥 호출 한것

    std::thread t(&foo); // 새로운 스레드를 생성해서 foo 실행
                        // start() 등의 함수 필요 없음
                        // 이순간 바로 스레드 생성..

    // 스레드를 생성한 경우 반드시
    // 1. 스레드 종료를 대기하거나
    // 2. 스레드를 분리해야 합니다.
    // t.join();   // 스레드 종료를 대기
    t.detach();    // 스레드 분리.
                // 단, 이 경우 주스레드가 종료 되면 
                // 실행중인 모든 스레드는 강제 종료 됩니다.
                // 되도록이면 모든 스레드 종료를 대기 하는것이
                // 좋은 모델입니다.

    std::cout << "finish main" << std::endl;
}

