// === 실제 구현을 가진 클래스 ===
// => Point 의 모든 기능을 여기서 제공합니다.
// PointImpl.h
class PointImpl
{
	int x, y;
	int debug; 
public:
	void print();
};

// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { }




// ==== 추상층 ===
// => 사용자는 이 클래스를 사용합니다.
// => 실제 기능 구현은 없습니다.
// => PointImp 의 기능을 사용합니다.
// 
// Point.h
//#include "PointImpl.h"
class PointImpl; // 핵심 : 전방선언만 있으면
				 //        헤더가 없어도, 포인터 변수는 선언가능
class Point
{
	PointImpl* impl;
public:
	Point();
	void print();
};


// Point.cpp
#include "Point.h"
#include "PointImpl.h" // 여기서는 헤더 필요
						// "new PointImpl" 하기 위해서
Point::Point() { impl = new PointImpl; }
void Point::print() { impl->print(); }





// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


// 위 기술이 C++ 진영에서는

// "PIMPL" 이라고 불리는 기술입니다.
// (Pointer to IMPLementation)

// Bridge 패턴을 컴파일 시간에 적용한것

// "컴파일러 방화벽" 이라고도 합니다.

// 장점 1. 컴파일 시간이 빨라 집니다.

// 장점 2. 완벽한 정보 은닉이 됩니다.
//		  (보안 강화)