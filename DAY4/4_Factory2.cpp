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

	// 클래스안에 자신의 객체를 만드는 static 멤버 함수를 제공하는 것은
	// 아주 유용하게 활용됩니다.
	// C++ 뿐 아니라 대부분의 객체지향언어에서 볼수 있는 좋은 기법

	static Shape* create() { return new Rect; }
};
// Rect 객체를 만드는 2가지 방법
// 1. Rect* r1 = new Rect;			// 클래스 이름을 직접 사용
// 2. Rect* r2 = Rect::create();	// 객체 생성 함수 호출

// 1. C++ 언어는 "클래스" 를 자료구조에 보관할수 없습니다
// v.push_back("Rect");  // 클래스를 보관한 것이 아니라 문자열 "Rect" 보관
	    				 // 문자열 "Rect" 로는 "Rect 객체 생성" 안됩니다.

// 2. 하지만 함수 포인터는 자료 구조에 보관 가능합니다
//    즉, 생성함수를 자료구조에 보관하면 나중에 보관된 정보로 객체 생성가능합니다
// v.push_back( &Rect::create );

// 이 외에도 "생성함수주소" 는 함수의 인자 등으로도 전달가능합니다.


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
}; 

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape * (*)(); // 함수 포인터 타입

	std::map<int, CREATOR> create_map; // <도형key, 생성함수> 를 자료구조에 보관

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
			p = it->second();   // 반복자 it 는 pair 의 포인터 역활 입니다
								// it->first : key
								// it->second : value 즉, 함수 포인터!
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




