#include <iostream>
#include <vector>


class NotImplemented {}; 


class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }


public:
	void draw()
	{
		std::cout << "mutex lock\n";
		draw_imp();
		std::cout << "mutex unlock\n";
	}

protected:
	virtual void draw_imp() = 0;

public:
	virtual Shape* clone() const { throw NotImplemented(); }
	virtual int get_area() const { return -1; }
};


class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Rect\n"; }

	Shape* clone() const override { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Circle\n"; }

	Shape* clone() const override { return new Circle(*this); }
};


int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;

		std::cin >> cmd;

		// 생각해볼 문제 #1. 객체의 생성과정을 OCP 를 만족하게 할수 없을까 ?
		//                  Triangle 이 추가되어도 아래 코드가 수정(추가)되지 않게
		// => 추상 팩토리(abstract factory) 패턴을 사용하면 됩니다 - 목요일날 구현

		// 생각해볼 문제 #2. Undo/Redo 를 추가하려면 어떻게 코드를 작성해야 할까요 ?
		// => "Command" 패턴을 사용하면 됩니다 - 목요일날 구현. 

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();	// OCP 만족, 좋은 코드
		}

		else if (cmd == 8)
		{
			std::cout << "몇번째 만든 도형을 복제 할까요 ?? ";
			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());	// OCP 만족, 좋은 코드

		}
	}
}
