#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <chrono>
#include <semaphore>
using namespace std::literals;

// mutex     : 자원의 독점  ( C++11)
// semaphore : 한정된 수량의 자원 공유 ( C++20 )

// 템플릿 인자 : 최대 카운트
// 생성자 인자 : 현재 카운트

// 규칙 : 0 <= 현재 카운트 <= 최대 카운트

std::counting_semaphore<3> sem(3);


void Download(std::string name)
{
    sem.acquire();  // if ( sem.count == 0 ) 대기
                    // else (--sem.count); 통과;


    for (int i = 0; i < 100; i++)
    {
        std::cout << name;
        std::this_thread::sleep_for(30ms);
    }
    std::cout << "\n finish " << name << std::endl;

    sem.release(); // sem.count += 1
}


int main()
{
    std::thread t1(Download, "1");
    std::thread t2(Download, "2");
    std::thread t3(Download, "3");
    std::thread t4(Download, "4");
    std::thread t5(Download, "5");

    t1.join();    t2.join();
    t3.join();    t4.join();
    t5.join();
}


