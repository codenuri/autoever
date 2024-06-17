#include <iostream>
#include <vector>

// Shape3.cpp : 좋지 않은 디자인
// Shape4.cpp : 좋은 디자인


// 핵심 #1. 모든 파생 클래스의 공통의 특징은
//          반드시 기반 클래스 에도 있어야 합니다.
//			문법적인 제약이 아닌 "디자인 관점"에서!!
//			Shape 에도 draw() 가 있어야 합니다.

// 핵심 #2. 기반 클래스 함수중 파생 클래스가 override 하게 되는 것은
//			반드시 "virtual"로 해야 한다.


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	// 아래 함수는 virtual 로 할까요? non-virtual ?
	// => 파생클래스가 override 할 이유가 없다. 
	// => non-virtual
	// => virtual 로 해도 되긴하지만, 필요 없는 것을 virtual 로하면
	//    "overhead" 가 있습니다.
	void set_color(int c) { color = c; }

	// virtual ? non-virtual
	// => 면적을 구하는 방법은 도형마다 다릅니다.
	// => 각 도형이 override 하게 됩니다.
	// => virtual !!!
	virtual int get_area() const { return 0; }


	virtual void draw() { std::cout << "draw Shape\n"; }
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
