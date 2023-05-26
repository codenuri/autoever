#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <chrono>
#include <semaphore>
using namespace std::literals;

// mutex     : 뮤텍스를 획득한 스레드만 unlock 가능 - 소유권개념이 있음
// semaphore : 소유권 개념이 없습니다.
//             누구나 카운트 증가 가능합니다.
//              단, 항상 현재 카운트는 최대값보다 작아야 합니다.

std::counting_semaphore<3> sem(3);

void Download(std::string name)
{
    sem.acquire();  

    for (int i = 0; i < 100; i++)
    {
        std::cout << name;
        std::this_thread::sleep_for(30ms);
    }
    std::cout << "\n finish " << name << std::endl;

//    sem.release(); // sem.count += 1
}


int main()
{
    std::thread t1(Download, "1");
    std::thread t2(Download, "2");
    std::thread t3(Download, "3");
    std::thread t4(Download, "4");
    std::thread t5(Download, "5");

    std::this_thread::sleep_for(1s);

    sem.release(2); // 주스레드가 세마 포어 카운트를 2증가
                    //

    t1.join();    t2.join();
    t3.join();    t4.join();
    t5.join();
}


