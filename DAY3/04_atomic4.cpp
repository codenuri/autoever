#include <iostream>
#include <atomic>

struct Point
{
    int x, y;
    Point() = default;

    // 사용자가 복사 생성자를 만든 경우
    // Point(const Point& other ) : x(other.x), y(other.y) {}

    //Point(const Point&) = default;
};

// trivial : special member function 이 널리 알려진대로 동작하는 것
// trivial constructor 
// => 사용자가 만든 생성자가 없고, 아무일도 하지 않는 생성자

// trivial copy constructor 
// => 가상함수가 없고, 사용자가 만든 복사 생성자 없는 경우
// => 즉, 모든 멤버를 얕은 로 복사 할수 있는 컴파일러가 제공한 복사 생성자

std::atomic<Point> pt;

int main()
{
    Point ret = pt.load();
}

