#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

// 은행 계좌
struct  Account
{
    std::mutex m; // money 의 동시 접근을 막기 위한 뮤텍스
    int money = 100;
};

// 계좌 이체
// 아래 코드는 2개의 스레드가 각각 하나의 뮤텍스를 잡고
void transfer(Account& acc1, Account& acc2, int cnt)
{
    // 아래 처럼하면 사용자가 직접 unlock 하거나..
    // 각각의 뮤텍스에 대해서 별도의 lock_guard 필요
    // std::lock(acc1.m, acc2.m); 

    
//  std::scoped_lock<std::mutex, std::mutex> g(acc1.m, acc2.m);
                // C++17 부터 제공됩니다.
                // => 생성자에서 std::lock() 사용

    // C++17 부터는 클래스 템플릿도 템플릿 인자 생략 가능합니다

    std::scoped_lock g(acc1.m, acc2.m);

    acc1.money -= cnt;
    acc2.money += cnt;
    std::cout << "finish transfer" << std::endl;

//    acc2.m.unlock();
//    acc1.m.unlock();
}

int main()
{
    Account kim, lee;
    std::thread t1(transfer, std::ref(kim), std::ref(lee), 5);
    std::thread t2(transfer, std::ref(lee), std::ref(kim), 5);
    t1.join();
    t2.join();
}

