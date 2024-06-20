#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	virtual Shape* clone() override  { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
	virtual Shape* clone() override { return new Circle(*this); }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> prototype_map; 

public:
	void register_sample(int key, Shape* sample)
	{
		prototype_map[key] = sample;
	}

	Shape* create(int type)
	{
		Shape* p = nullptr;

		auto it = prototype_map.find(type);

		if (it != prototype_map.end())
		{
			p = it->second->clone(); // ����� �ߺ��� ���纻 ����.
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




// �� �ڵ�� 

// 1. Ư�� �Ӽ��� ���� ��ü�� ���� �����ϰ� �ȴٸ�

// 2. �ߺ����� ����� ��ü�� �̸� ���� ���� ����� ����

// 3. �ʿ��Ҷ� "����(clone)" �� ���ؼ� ��ü�� �����ϰ� �ֽ��ϴ�.

// �̷� ������ "prototype" �Դϴ�.