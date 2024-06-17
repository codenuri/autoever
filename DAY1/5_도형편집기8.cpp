#include <iostream>
#include <vector>


// 핵심 #1. template method 패턴
// => 모든 파생 클래스에 공통의 적용되는 변하지 않은 전체적인 흐름을 담은 코드를
//    기반 클래스가 제공
// => 변해야 하는 부분만 가상함수화 해서 파생 클래스가 변경할수 있는 기회 제공.
// => 가장 널리 사용되는 디자인 패턴.
// => 내일 부터 계속 등장




class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }
	virtual int get_area() const { return 0; }

	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 있는 변해야 하는 코드는 분리한다.
	// => 변해야 하는 코드를 별도의 가상함수로 분리한다.

protected:
	virtual void draw_imp()
	{
		std::cout << "draw Shape\n";
	}

public:
	void draw() 
	{ 
		std::cout << "mutex lock\n";
		draw_imp();
		std::cout << "mutex unlock\n";
	}





	virtual Shape* clone() const { return new Shape(*this); }
};




class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw Rect\n"; }

	virtual Shape* clone() const { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void draw_imp() { std::cout << "draw Circle\n"; }

	virtual Shape* clone() const { return new Circle(*this); }
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
