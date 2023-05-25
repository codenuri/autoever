#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

// 핵심 : mutex 를 사용할때 되도록이면 직접
//       lock()/unlock() 하지 마세요.
//       lock 관리도구(4개)를 사용하세요.

// => 직접 lock 하면.. 예외 등이 발생시
//    "dead lock" 이 될수 있습니다.

std::mutex m;

void goo()
{
    m.lock();    
    std::cout << "using shared data" << std::endl;

    // 공유자원 사용중 다양한 이유로 예외 발생
    throw std::runtime_error("goo fail");

    m.unlock();
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



