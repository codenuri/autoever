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
}

