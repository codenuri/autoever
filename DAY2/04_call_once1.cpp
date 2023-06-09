#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;
// 아래 init 은 스레드 별로 호출됩니다.
// => 즉, 스레드별 초기화
// => 스레드가 5개면 각각의 스레드에 대해서 init 호출
void init(int a, double d)
{
    std::cout << "init" << std::endl;
    std::this_thread::sleep_for(2s);
}
void foo()
{
    std::cout << "start foo" << std::endl;
    init(10, 3.4);    // 초기화

    std::cout << "finish foo" << std::endl;
}
int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}



