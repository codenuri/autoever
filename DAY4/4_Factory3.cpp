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


// ���忡 �ڵ� ����� �ϱ� ���� Ŭ����
class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*creator)() )
	{
		ShapeFactory::get_instance().register_shape(key, creator);
	}
};

// �Ʒ� ������ �����غ�����. 
// �������� �����ڿ� main �Լ��� ���� ����Ǵ°��� ?
// => �������� ������
// AutoRegister ar(1, &Rect::create);








class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }


	// static ��� ����Ÿ�� Ư¡�� �� ������ ������
	// => ��� ��ü�� ����
	// => "��ü�� ��� �޸𸮿� ����", ��, ��ü�� ������ �ʾƵ� �����ڴ� ȣ���.
	//    ���������� ���� �ϹǷ� main �Լ� �������� ������ ȣ���. 
	static AutoRegister ar{ 1, &Rect::create };
};

// Rect r1;	// ��ü�� �����ϴ� ������ ȣ��
// Rect r2;	// ������ ȣ��
// Rect r3;	// ������ ȣ��.
//			=> ��, �����ڴ� ��ü�� �ѹ� ȣ��

// ������, "Rect::ar" �� �����ڴ� main �Լ� ������ ���ʿ� 1ȸ�� ȣ���.
// => �ᱹ, Ŭ������ �ѹ� ȣ�� �Դϴ�.
// => Ŭ���� �����ڶ�� �����Ҽ� �ֽ��ϴ�.
// => C# �� �ִ� "static ������ ����" �� C++ �� �䳻����!

// C# �ڵ�
class Car
{
	public Car() {} // instance ������. - ��ü�� �ѹ��� ȣ��
	static Car() {} // static ������.   - ���ʿ� 1ȸ�� ȣ��
};





class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};



int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	factory.register_shape(1, &Rect::create);
	factory.register_shape(2, &Circle::create);


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




