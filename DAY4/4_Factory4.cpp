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


// 공장에 자동 등록을 하기 위한 클래스
class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*creator)())
	{
		ShapeFactory::get_instance().register_shape(key, creator);
	}
};



// 새로운 도형 클래스를 만들때 지켜야 하는 규칙을 자동생성하는 매크로 제공

#define REGISTER(key, classname)								\
	static Shape* create() { return new classname; }			\
	inline static AutoRegister ar{ key, &classname::create };


// 이제 새로운 도형을 만들게 되면 클래스 선언에 "REGISTER" 매크로만
// 넣으면, 기존 시스템 코드는 어떠한 수정을 하지 않아도 됩니다.

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	REGISTER(1, Rect)
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
	REGISTER(2, Circle)
};

class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }
	REGISTER(3, Triangle)
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




