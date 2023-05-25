#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

// C++ 격언 : 자원 관리는 항상 생성자/소멸자에 의존해라!
//           RAII 라는 이름을 가진 격언

template<typename T>
class lock_guard
{
    T& mtx;
public:
    lock_guard(T& m) : mtx(m) { mtx.lock(); }
    ~lock_guard()             { mtx.unlock(); }
};


std::mutex m;


void goo()
{   
    {
        std::lock_guard<std::mutex> g(m);
//      lock_guard<std::mutex> g(m);    // 생성자에서 m.lock()
        // 소멸자에서 m.unlock();
        // 예외가 발생해도. 
        // 지역변수 g의 소멸자 호출은 보장
        // 스택풀기(stack unwinding)
        //  m.lock();
        std::cout << "using shared data" << std::endl;
        throw std::runtime_error("goo fail");
        //  m.unlock();
    }

}



void foo()
{
    try { goo(); }
    catch (...) { std::cout << "예외 발생" << std::endl; }
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}



