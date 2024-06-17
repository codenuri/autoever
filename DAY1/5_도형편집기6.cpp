#include <iostream>
#include <vector>


class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }
	virtual int get_area() const { return 0; }
	virtual void draw() { std::cout << "draw Shape\n"; }
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
		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();	
		}

		else if (cmd == 8)
		{
			std::cout << "몇번째 만든 도형을 복제 할까요 ?? ";
			int k;
			std::cin >> k;

			// k번째 도형과 동일한 복제본을 만들어서 v에 추가합니다.
			// 그런데, 어떻게 구현해야 할까요 ? k 번째 도형이 뭘까요 ?

			// 방법 #1. dynamic_cast 로 조사하자!
			if (dynamic_cast<Rect*>(v[k]) != nullptr)
			{
				v.push_back(new Rect(*v[k]) );
			}
			else if (dynamic_cast<Circle*>(v[k]) != nullptr)
			{
				v.push_back(new Circle(*v[k]));
			}

		}
	}
}
