#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

std::mutex m;
int shared_data = -1; // 쓰레기값, 생산되기 이전의 값

// 아래 코드는 공유 자원에 대한 동시접근은 해결했습니다.
// 그런데, 생산자가 생산하기 전에 소비자가 소비하고 있습니다.
// => 생산후에 소비 하도록 변경해야 합니다.

void consumer()
{
    std::lock_guard<std::mutex> lg(m);
    std::cout << "consume : " << shared_data << std::endl;
}
void producer()
{
    std::this_thread::sleep_for(10ms);
    std::lock_guard<std::mutex> lg(m);
    shared_data = 100;
    std::cout << "produce : " << shared_data << std::endl;
}
int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join(); 
    t2.join();
}