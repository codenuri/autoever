#include <chrono>
#include <iostream>
#include <thread>
using namespace std::literals;

// C++20 의 std::jthread 
// 1. 소멸자에서 자동 join
// 2. 협력적 취소 모델 제공

void foo( std::stop_token token)
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(500ms);
        std::cout << "foo : " << i << std::endl;

        // 주기적으로 취소 요청을 확인합니다.
        if (token.stop_requested())
            break;
    }
    std::cout << "finish... foo\n";
}



void goo()
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(500ms);
        std::cout << "goo : " << i << std::endl;
    }
}
int main()
{
    // 핵심 1. jthread 인자로 함수외에 어떤 다른 것도 전달하지 않습니다.
    std::jthread j1(&foo); // foo(std::stop_token) 모양
    std::jthread j2(&goo); // goo()

    std::this_thread::sleep_for(2s);

    
    j1.request_stop(); // 멈춰달라는 요청
    j2.request_stop(); // 요청할수 있지만,
                        // 인자를 받아서 조사하는 코드가 없으므로
                        // 요청은 무시 됩니다.
}