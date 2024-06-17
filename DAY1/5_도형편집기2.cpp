#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {} 
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

		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)	// A
				p->draw();		// B. error
		}
	}
}
// #1. �� �ڵ�� �� ���� �ϱ�� ?
// => A �κп��� "auto p" �� �ᱹ "Shape* p" �Դϴ�.
// => �׷���, Shape ���� draw() �� �����ϴ�.
// => �׷��� "B" �κп��� ����!!
// 
// #2. �ذ�å�� ����� ?
// => ���� �ҽ�����!!(Shape3.cpp, Shape4.cpp)
