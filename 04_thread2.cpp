#include <iostream>
#include <string>
#include <thread>

void f1() { }
void f2(int a, double d) { }
void f3(int a, int& b, std::string&& s) { b = 100; }

int main()
{
    int n = 0;
    std::string s = "hello";

    // 인자 전달 방법
    std::thread t1(&f1); // 인자 없는 함수

    std::thread t2(&f2, 3, 3.4); // 인자 2개 전달

    // 핵심 : 참조로 전달하는 기술
    //       단, 위험하니 주의 해서 사용
    std::thread t3(&f3, std::ref(n), std::move(s));

    t1.join();
    t2.join();
    t3.join();
}

