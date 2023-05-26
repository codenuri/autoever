#include <iostream>
#include <thread>
#include <atomic>

struct Point   { int x, y; };    // 64bit 구조체
struct Point3D { int x, y, z; }; // 96bit 구조체

std::atomic<int>   a1;
std::atomic<Point> a2;
std::atomic<Point3D> a3;

int main()
{
    ++a1;
    int n = a1.load();
    Point pt = a2.load(); // 스레드에 안전하게 읽어오기

    // a1에 대한 기본 연산이 "lock-free" 를 지원하는가 ?
    std::cout << a1.is_lock_free() << std::endl;
    std::cout << a2.is_lock_free() << std::endl;
    std::cout << a3.is_lock_free() << std::endl; // false

    Point3D pt2 = a3.load(); // 멀티 스레드에는 안전합니다.
                             // 하지만, CPU 명령(lock-free)를 사용하는것이 아니라
                             // 다른 방법으로 동기화 합니다.
                             // ( 대부분 spin lock 사용 )
                             // => spin lock 은 계속 CPU 사용하므로 
                            //     오버헤드 있습니다.
}

