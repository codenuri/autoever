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

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);

		// 해결책 #1. 캐스팅!!
		// => 아래 코드는 아무 문제 없이 잘 동작합니다.
		// => 이 코드의 단점은 뭘까요 ?
		else if (cmd == 9)
		{
			for (auto p : v) // "Shape* p" 
			{
				if (dynamic_cast<Rect*>(p) != nullptr)
				{
					static_cast<Rect*>(p)->draw();
				}
				else if (dynamic_cast<Circle*>(p) != nullptr)
				{
					static_cast<Circle*>(p)->draw();
				}

			}
		}
	}
}

