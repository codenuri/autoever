#include <iostream>
#include <vector>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// 클래스안에 자신의 객체를 만드는 static 멤버 함수를 제공하는 것은
	// 아주 유용하게 활용됩니다.
	// C++ 뿐 아니라 대부분의 객체지향언어에서 볼수 있는 좋은 기법

	static Shape* create() { return new Rect; }
};
// Rect 객체를 만드는 2가지 방법
// 1. Rect* r1 = new Rect;			// 클래스 이름을 직접 사용
// 2. Rect* r2 = Rect::create();	// 객체 생성 함수 호출










class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* create(int type)
	{
		Shape* p = nullptr;
		if (type == 1)	p = new Rect;
		else if (type == 2)	p = new Circle;
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd > 0 && cmd < 8) 
		{
			Shape* s = factory.create(cmd);

			if (s != nullptr)
				v.push_back(s);
		}




		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw(); 
			}
		}
	}
}




