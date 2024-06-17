#include <iostream>
#include <vector>


class NotImplemented {}; // 예외를 위한 클래스


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

	// 가상함수      : 파생 클래스가 override 하지 않으면 기본 구현을 제공하겠다는 의미
	// 순수 가상함수 : 파생 클래스가 반드시 구현을 제공하라고 지시하는 것. 

protected:
	virtual void draw_imp() = 0;

public:

//	virtual Shape* clone() const = 0; // 이렇게 해도 되고!! 좋은 코드!!

	// 아래 같이 만드는 경우도 있습니다.
	// 1. override 하지 않고 사용하면 예외 발생
	// 2. override 하지 않고 사용하지도 않으면 ok
	// 3. override 하고 사용하면 ok. 
	// => 즉, 사용하는 경우만 override 하면 된다는 것. "파이썬 등에서 많이 사용"

	virtual Shape* clone() const { throw NotImplemented(); }


	// 아래 코드도 "=0", "기본 구현 예외"로 해도 되고
	// => 실패를 나타내는 값을 반환하게 해도 됩니다.
	// => "get_area() 호출시 -1이 나오면 면적구할수 없음" 이라고 매뉴얼작성.
	virtual int get_area() const { return -1; }

};


class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Rect\n"; }

	Shape* clone() const override  { return new Rect(*this); }
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

			v.push_back(v[k]->clone());


		}
	}
}
