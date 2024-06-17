#include <iostream>
#include <vector>

// Shape3.cpp : 좋지 않은 디자인
// Shape4.cpp : 좋은 디자인


// 핵심 #1. 모든 파생 클래스의 공통의 특징은
//          반드시 기반 클래스 에도 있어야 합니다.
//			문법적인 제약이 아닌 "디자인 관점"에서!!
//			Shape 에도 draw() 가 있어야 합니다.


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void draw() { std::cout << "draw Shape\n"; }
};


class Rect : public Shape
{
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
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;

		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)	
				p->draw();		
		}
	}
}
