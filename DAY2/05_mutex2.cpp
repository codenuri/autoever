#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

std::mutex m;

int share_data = 0; // 파일 같은 공유 자원이라고 생각해 봅시다.

void foo()
{
//  m.lock(); // 뮤텍스를 획득하지 못한 경우 대기

    if (m.try_lock()) // 뮤텍스를 획득하지 못한 경우 false 반환
    {
        share_data = 100;

        m.unlock();
    }
    else
    {
        // 뮤텍스 획득에 실패한 경우 다른 작업 수행
    }
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);

    t1.join();
    t2.join();
}



