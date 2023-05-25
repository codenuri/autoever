#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std::literals;

void foo(std::promise<int>&& p)
{
    std::cout << "start foo" << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << "finish foo" << std::endl;
    p.set_value(10);
}
int main()
{
    std::promise<int> p;
    std::future<int> ft = p.get_future();

    std::thread t(foo, std::move(p));
    t.detach();
//  ft.get(); // 핵심. ft.get()을 생략했습니다.

}   // 

// 핵심 
// async 에서 꺼내는 future : 소멸자에서 get() 수행
//                      => 함수가 return 으로 결과를 반환하므로
//                      => 함수의 종료를 안전하게 대기한다는 의미
// 
// promise 에서 꺼내는 future : 소멸자에서 get() 수행안함
//                      => 스레드 함수의 return 이 아닌 
//                         p.set_value() 의 결과를 대기
//                      => 결국 ft.get()의 함수의 종료 대기가 아니라
//                          결과를 얻는것.




