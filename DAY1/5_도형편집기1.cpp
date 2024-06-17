#include <iostream>
#include <vector>

// 파워 포인트 같은 프로그램을 "객체지향 설계"로 만드는 것을
// 생각해 봅시다.

// 1. 모든 도형을 타입으로 설계하면 편리하다.

// 2. 모든 도형의 공통의 특징은 기반 클래스를 만들어서 제공한다.
//    기반 클래스가 있으면 "모든 도형을 하나의 컨테이너에 보관" 할수 있다. - 핵심

class Shape
{
	int color;
public:
	virtual ~Shape() {}  // 가상 소멸자. 
};


class Rect : public Shape
{
//	int x, y, w, h;  int color, 생성자등은 생략
public:
	void draw() { std::cout << "draw Rect\n"; }
};
class Circle : public Shape
{	
public:
	void draw() { std::cout << "draw Circle\n"; }
};

int main()
{
//	std::vector<Rect*> v;	// Rect 객체만 저장 가능. 
	std::vector<Shape*> v;	// 모든 도형을 하나의 컨테이너에 보관
							// => 도형을 생성한 순서가 기록된다.
							// => 도형의 겹치는 부분(z-order)에서 위에 놓일 도형을
							//    판단할수 있다.
}

