#include <iostream>
#include <vector>
#include <map>
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

	static Shape* create() { return new Rect; }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)(); 
	std::map<int, CREATOR> create_map; 
public:
	void register_shape(int key, CREATOR c)
	{
		create_map[key] = c;
	}

	Shape* create(int type)
	{
		Shape* p = nullptr;

		auto it = create_map.find(type);

		if (it != create_map.end())
		{
			p = it->second();   
		}
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// �Ʒ� �ڵ�� ���忡 "�����Լ�"�� ����ϴ� �ڵ��Դϴ�.
	// => ��ϵ� �����Լ��� "��ü�� ����" �ϰ� �˴ϴ�.
	// => �׷���, �Ʒ� �ڵ�� �ᱹ "Ŭ����"�� ����ϴ� ȿ�� �Դϴ�.
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);

	// ���忡 "Ŭ����" �� �ƴ�

	// Ư�� ���¸� ���� ��ü�� ���� �����ϰ� �ȴٸ�
	// �̸� "�ߺ�(prototype)" �� ���� ���忡 �����, ���縦 ���ؼ� ��ü����

	Rect* red_rect = new Rect;
	Rect* blue_rect = new Rect;
	Circle* red_circle = new Circle;

	factory.register_sample(1, red_rect);
	factory.register_sample(2, blue_rect);
	factory.register_sample(3, red_circle);







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




