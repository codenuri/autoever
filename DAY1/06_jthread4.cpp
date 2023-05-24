#include <chrono>
#include <iostream>
#include <thread>
using namespace std::literals;

void foo(bool& quitFlag)
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(500ms);
        std::cout << "foo : " << i << std::endl;

        // 스레드는 주기적으로 "flag" 를 조사해야 합니다.
        if (quitFlag == true)
            break;

    }
    // 사용하던 자원은 안전하게 정리하고 종료
    std::cout << "finish...foo\n";
}


int main()
{
    bool quitFlag = false;

    std::thread t(foo, std::ref(quitFlag) );

    std::this_thread::sleep_for(2s);

    quitFlag = true;

    t.join();
}