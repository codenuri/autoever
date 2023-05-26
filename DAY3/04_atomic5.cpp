#include <iostream>
#include <atomic>
#include <type_traits>

struct Point
{
    int x, y;
//  Point() = default; // 컴파일러가 제공. trivial
    Point() {};        // 사용자가 만든 생성자, trivial 하지 않음

    Point(const Point& other ) : x(other.x), y(other.y) {}

    //Point(const Point&) = default;
};

int main()
{
    std::cout << std::is_trivially_copy_constructible_v<Point> << std::endl;

    std::cout << std::is_trivially_default_constructible_v<Point> << std::endl;

}

