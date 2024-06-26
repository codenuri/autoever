#include <iostream>
#include <vector>

// 리팩토링 : 새로운 기능을 추가하는 것이 아니라, 
//            기존 코드를 좋은 구조로 변경하는 것. 

// 핵심 #1. 리팩토링에서 사용되는 아주 유명한 용어 입니다. 의미를 생각해 보세요

// "replace conditional with polymorphism"
// "        제어문(if, switch) 를 다형성(가상함수)로 변경해라"
// 
// Shape3.cpp 를 Shape4.cpp 로 변경해라
// Shape6.cpp 를 Shape7.cpp 로 변경해라



// 핵심 #2. 디자인 패턴이란 ?
// => 1994년에 발간된 책의 제목
// => 4명의 저자!
// => 자주 사용되는 코딩 스타일에 이름을 부여 한것 
// => 23개의 이름을 부여
// => 코딩 기법 자체를 만든것이 아니라 "기존에 존재하던 기법에 이름 부여"
// => 4명의 도둑 이라는 의미로 "Gang's Of Four" 라고도 하고, 약자로 GOF 라고 합니다.
//    GoF's Design Pattern  

// 핵심 #3. Prototype 디자인 패턴
// => 객체를 먼저 만들고, 복사본을 사용해서 객체를 생성하는 기법
// => clone() 가상함수.
// => "목요일에 제대로된 예제 등장"







class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }
	virtual int get_area() const { return 0; }
	virtual void draw() { std::cout << "draw Shape\n"; }


	// 자신의 복사본을 만드는 가상함수는 항상 유용하게 활용 됩니다.
	virtual Shape* clone() const { return new Shape( *this ); }
};




class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }

	virtual Shape* clone() const { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }

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

			// 방법 #2. 다형성!!!
			// => OCP 를 만족하는 좋은 디자인
			// => 다형성은 결국 "해당 기능을 수행하는 가상함수" 를 만들라는 것!

			v.push_back( v[k]->clone() );	// 다형성 활용!!
											// => k 번째 도형이 무엇인지 알필요없다.
											// => 새로운 도형이 추가되어도 
											//	  이 코드는 수정될 필요 없다.


		}
	}
}
