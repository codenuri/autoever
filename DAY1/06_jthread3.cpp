#include <iostream>
#include <thread>

void foo(int a, int b)
{
    std::cout << "foo : " << a << ", " << b << std::endl;
}

int main()
{
    // 1. std::thread 사용시 반드시 join 또는 detach 필요
    std::thread t1(&foo, 10, 20);
    std::thread t2(&foo, 10, 20);
    t1.join();
    t2.join();

    // 2. C++20 에서 추가된 std::jthread.. 
    //    소멸자에서 자동으로 join() 호출
    //    원리는 이전예제의 join_thread 클래스 참고.
    //    g++ 소스.cpp -std=c++20
    //    cl  소스.cpp /std:c++20
    //    VS : 프로젝트, 속성 메뉴에서 C++버전 설정
    std::jthread jt1(&foo, 10, 20);
    std::jthread jt2(&foo, 10, 20);

}

