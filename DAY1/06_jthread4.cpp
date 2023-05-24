#include <chrono>
#include <iostream>
#include <thread>
using namespace std::literals;

void foo()
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(500ms);
        std::cout << "foo : " << i << std::endl;
    }
}
int main()
{
    std::thread t(foo);

    std::this_thread::sleep_for(2s);

    t.join();
}