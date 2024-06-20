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
	AutoRegister(int key, Shape* (*creator)() )
	{
		ShapeFactory::get_instance().register_shape(key, creator);
	}
};

// 아래 한줄을 생각해보세요. 
// 전역변수 생성자와 main 함수중 먼저 실행되는것은 ?
// => 전역변수 생성자
// AutoRegister ar(1, &Rect::create);








class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }


	// static 멤버 데이타의 특징을 잘 생각해 보세요
	// => 모든 객체가 공유
	// => "객체가 없어도 메모리에 존재", 즉, 객체를 만들지 않아도 생성자는 호출됨.
	//    전역변수와 유사 하므로 main 함수 실행전에 생성자 호출됨. 
	static AutoRegister ar{ 1, &Rect::create };
};

// Rect r1;	// 객체를 생성하는 생성자 호출
// Rect r2;	// 생성자 호출
// Rect r3;	// 생성자 호출.
//			=> 즉, 생성자는 객체당 한번 호출

// 하지만, "Rect::ar" 의 생성자는 main 함수 이전에 최초에 1회만 호출됨.
// => 결국, 클래스당 한번 호출 입니다.
// => 클래스 생성자라고 생각할수 있습니다.
// => C# 에 있는 "static 생성자 개념" 을 C++ 로 흉내낸것!

// C# 코드
class Car
{
	public Car() {} // instance 생성자. - 객체당 한번씩 호출
	static Car() {} // static 생성자.   - 최초에 1회만 호출
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




