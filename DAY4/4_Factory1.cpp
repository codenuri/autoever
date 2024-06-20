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
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

// ������ ����� ���丮
// => �ǹ� : ���� ��ü�� ������ "�Ѱ�" ������ �ϰ� �˴ϴ�.
// => ���ο� ���� �߰��� "�Ѱ�(���丮)" �� �����Ǹ� �˴ϴ�.
// => �ڵ� ������ �ּ�ȭ �Ҽ� �ֽ��ϴ�.

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* create(int type)
	{
		Shape* p = nullptr;
		if      (type == 1)	p = new Rect;
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

		if (cmd > 0 && cmd < 8) // 1 ~ 7 ���� ������ ��ȣ�� ����
		{
			Shape* s = factory.create(cmd);

			if (s != nullptr)
				v.push_back(s);
		}




		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw(); // ������, OCP ����
			}
		}
	}
}




