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

	// Ŭ�����ȿ� �ڽ��� ��ü�� ����� static ��� �Լ��� �����ϴ� ����
	// ���� �����ϰ� Ȱ��˴ϴ�.
	// C++ �� �ƴ϶� ��κ��� ��ü������� ���� �ִ� ���� ���

	static Shape* create() { return new Rect; }
};
// Rect ��ü�� ����� 2���� ���
// 1. Rect* r1 = new Rect;			// Ŭ���� �̸��� ���� ���
// 2. Rect* r2 = Rect::create();	// ��ü ���� �Լ� ȣ��

// 1. C++ ���� "Ŭ����" �� �ڷᱸ���� �����Ҽ� �����ϴ�
// v.push_back("Rect");  // Ŭ������ ������ ���� �ƴ϶� ���ڿ� "Rect" ����
	    				 // ���ڿ� "Rect" �δ� "Rect ��ü ����" �ȵ˴ϴ�.

// 2. ������ �Լ� �����ʹ� �ڷ� ������ ���� �����մϴ�
//    ��, �����Լ��� �ڷᱸ���� �����ϸ� ���߿� ������ ������ ��ü ���������մϴ�
// v.push_back( &Rect::create );

// �� �ܿ��� "�����Լ��ּ�" �� �Լ��� ���� �����ε� ���ް����մϴ�.


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
}; 

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape * (*)(); // �Լ� ������ Ÿ��

	std::map<int, CREATOR> create_map; // <����key, �����Լ�> �� �ڷᱸ���� ����

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
			p = it->second();   // �ݺ��� it �� pair �� ������ ��Ȱ �Դϴ�
								// it->first : key
								// it->second : value ��, �Լ� ������!
		}
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




