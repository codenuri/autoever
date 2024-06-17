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
		//    새로운 도형(Triangle)이 추가되면 코드가 수정(추가)되어야 합니다.
		// => 아래 코드는 "OCP" 를 만족할수 없는 좋지 않은 디자인 입니다.
		// => "dynamic_cast"를 사용하면 대부분 제어문이 등장하고
		//     제어문은 "OCP" 를 만족할수 없는 경우가 많습니다.

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

