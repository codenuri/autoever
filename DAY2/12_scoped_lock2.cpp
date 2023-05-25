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
// 다른 뮤텍스를 요구하는 현상이 발생합니다.
// => deadlock 이 발생할수 있습니다.
void transfer(Account& acc1, Account& acc2, int cnt)
{
//    acc1.m.lock();
//    acc2.m.lock();

    // 2개 이상의 뮤텍스를 lock 하려면
    // "deadlock avoid 알고리즘" 으로 구현된 함수를 사용해야 합니다.
    // std::lock(m1, m2, m3, m4....)
    std::lock(acc1.m, acc2.m);

    acc1.money -= cnt;
    acc2.money += cnt;
    std::cout << "finish transfer" << std::endl;

    acc2.m.unlock();
    acc1.m.unlock();
}

int main()
{
    Account kim, lee;
    std::thread t1(transfer, std::ref(kim), std::ref(lee), 5);
    std::thread t2(transfer, std::ref(lee), std::ref(kim), 5);
    t1.join();
    t2.join();
}

