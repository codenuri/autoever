// main 에서 Point 를 직접 사용하는 예제
// => 즉, 간접층(추상층)이 없는 경우
// => A 부분이 추가되면 모든 소스 파일이 다시 컴파일 되어야 한다.
// => 독립적인 update 가 될수 없다.
// 
// Point.h
class Point
{
	int x, y;
	int debug; // A. 나중에 추가
public:
	void print();
};

// Point.cpp
#include "Point.h"

void Point::print() { } // 구현 생략



// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


