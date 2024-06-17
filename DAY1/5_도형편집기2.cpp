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

		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)	// A
				p->draw();		// B. error
		}
	}
}
// #1. 위 코드는 왜 에러 일까요 ?
// => A 부분에서 "auto p" 은 결국 "Shape* p" 입니다.
// => 그런데, Shape 에는 draw() 가 없습니다.
// => 그래서 "B" 부분에서 에러!!
// 
// #2. 해결책은 뭘까요 ?
// => 다음 소스에서!!(Shape3.cpp, Shape4.cpp)
