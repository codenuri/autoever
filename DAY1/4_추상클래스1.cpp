// 1_추상클래스1.cpp - 10page

// 추상 클래스(abstract class) : 순수 가상함수가 한개 이상있는 클래스
// 특징 : 객체를 생성할수 없다. 포인터 변수는 만들수 있다.

// 의도 : 약속된 특정 함수를 반드시 만들라고 지시하는 것

class Shape
{
public:
	virtual void draw() = 0; // 순수 가상함수(pure virtual function)
							 // => 구현부가 없고, "= 0" 으로 표기
};
class Rect : public Shape
{
public:
	// draw() 의 구현부를 제공하지 않으면 Rect 도 추상(abstract)
	// draw() 의 구현부를 제공하면        Rect 도 추상아님(concrete, 구체)
	void draw() override {}
};
int main()
{
	Shape  s; // error.
	Shape* p; // ok
	Rect  r;  // ok
}
