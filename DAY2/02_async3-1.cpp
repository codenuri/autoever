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

    std::cout << "continue main" << std::endl;

}

