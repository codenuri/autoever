#include <iostream>
#include <atomic>
#include <type_traits>

struct Point
{
    int x, y;
    Point() = default;

    Point(const Point& other ) : x(other.x), y(other.y) {}

    //Point(const Point&) = default;
};

int main()
{
    std::cout << std::is_trivially_copy_constructible_v<Point> << std::endl;
    std::cout << std::is_trivially_default_constructible_v<Point> << std::endl;

}

