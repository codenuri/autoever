#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std::literals;

int add(int a, int b)
{
    std::cout << "add : " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(2s);

    std::cout << "finish add" << std::endl;
    return a + b;
}
int main()
{
    // 핵심 : async 의 리턴 값을 받지 않을때 나오는 현상
    std::async(add, 10, 20);
        // => async() 가 반환한것은 future의 임시객체
        // => 임시객체는 다음문장으로 내려가기 전에 파괴됩니다.
        // => 임시객체의 소멸자에서 get() 수행..!!
        // => 결국, 스레드가 수행을 마칠때 까지 대기 하게 됩니다.

    // 주스레드가 대기 하지 않고 바로 다음 문장을 실행되게 하려면
    // 반드시 return 값(future)을 받으세요.
    // => add 가 void 반환하면 std::future<void> 로 !

    //std::future<int> ft = std::async(add, 10, 20);

    std::cout << "main : " << std::this_thread::get_id() << std::endl;

}

