#include <iostream>
#include <thread>

// 스레드 함수의 모양
void foo(int a, double d) {}

struct Machine
{
    void Run(int a, double d) {}
};
struct Work
{
    void operator()(int a, double b) const {}
};

int main()
{
    // 모든 종류의 callable object 를 스레드로 수행 가능
    std::thread t1(&foo, 1, 3.4); // 1. 일반 함수

    // 2. 멤버 함수
    Machine m;
    std::thread t2(&Machine::Run, &m, 1, 3.4);
                                // m.Run(1, 3.4) 를 스레드로

    // 3. 함수객체
    Work w; // 객체지만
    w(1, 3.4); // 함수 처럼 사용가능
    std::thread t3(w, 1, 3.4); // 주의 &w 가 아닌 w. 

    // 4. 람다 표현식을 스레드로 => 요즘 유행.
    std::thread t4([](int a) {std::cout << "lambda\n"; }, 3);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

