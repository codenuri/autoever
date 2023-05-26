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
    Point pt; // 디폴트 생성자가 trivial 하면 호출 안함.
              // 디폴트 생성자가 trivial 하지 않으면 호출..
              // => 단, 최적화 단계에서 생략될수도 있음.

    std::cout << std::is_trivially_copy_constructible_v<Point> << std::endl;

    std::cout << std::is_trivially_default_constructible_v<Point> << std::endl;

}

