#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex>
#include <string>
using namespace std::literals;


// 1. 쓰는 동안에는 다른 스레드가 읽으면 안됩니다.
// 2. 쓰는 동안에는 다른 스레드가 쓰면 안됩니다.
// 3. 읽는 동안에는 다른 스레드가 쓰면 안됩니다.
// 4. 읽는 동안에는 다른 스레드가 읽어도 됩니다.

// shared_mutex1.cpp : 읽는 동안 다른 스레드는 읽을수 없습니다.
// shared_mutex2.cpp : 읽는 동안 다른 스레드는 읽을수 있도록

//std::mutex m;

std::shared_mutex m;
int share_data = 0;

void Writer()
{
    while (1)
    {
        m.lock();
        share_data = share_data + 1;
        std::cout << "Writer : " << share_data << std::endl;
        std::this_thread::sleep_for(1s);
        m.unlock();

        std::this_thread::sleep_for(10ms);
    }
}



void Reader(const std::string& name)
{
    while (1)
    {
        //m.lock();
        m.lock_shared();

        std::cout << "Reader(" << name << ") : " << share_data << std::endl;
        std::this_thread::sleep_for(500ms);
        
        //m.unlock();
        m.unlock_shared();

        std::this_thread::sleep_for(10ms);
    }
}

int main()
{
    std::thread t1(Writer);
    std::thread t2(Reader, "A");
    std::thread t3(Reader, "B");
    std::thread t4(Reader, "C");
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}



