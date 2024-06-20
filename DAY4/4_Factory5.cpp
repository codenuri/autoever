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
			p = it->second->clone(); // 저장된 견본의 복사본 생성.
		}
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 아래 코드는 공장에 "생성함수"를 등록하는 코드입니다.
	// => 등록된 생성함수로 "객체를 생성" 하게 됩니다.
	// => 그래서, 아래 코드는 결국 "클래스"를 등록하는 효과 입니다.
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);

	// 공장에 "클래스" 가 아닌

	// 특정 상태를 가진 객체를 많이 생성하게 된다면
	// 미리 "견본(prototype)" 을 만들어서 공장에 등록후, 복사를 통해서 객체생성

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




// 위 코드는 

// 1. 특정 속성을 가진 객체를 자주 생성하게 된다면

// 2. 견본으로 사용할 객체를 미리 만들어서 공장등에 등록해 놓고

// 3. 필요할때 "복사(clone)" 을 통해서 객체를 생성하고 있습니다.

// 이런 패턴을 "prototype" 입니다.