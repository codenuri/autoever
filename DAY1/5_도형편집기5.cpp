#include <iostream>
#include <vector>


// 핵심 #1. 다형성(polymorphism)
//			=> 동일한 표현식이 상황(실제 객체의 종류)에 따라
//			   다르게 동작하는것
// 
//			=> OCP를 만족하는 좋은 코드 입니다.
//			=> 항상 "다형성(가상함수)" 기반의 코드를 작성하세요!!

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
class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw Triangle\n"; }
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
				p->draw();	// 다형성(polymorphism)
							// => 동일한 표현식이 상황(실제 객체의 종류)에 따라
							//    다르게 동작하는것

			// 객체지향 언어의 3가지 특징 : 캡슐화, 상속, 다형성
		}
	}
}
