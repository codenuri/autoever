#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.
// 
// TextView : 문자열을 보관하고 있다가 화면에 이쁘게 출력하는 기능.
class TextView
{
	// font 이름, 크기, 색상등 다양한 멤버 있음. 
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};





class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};
// 도형편집기 시스템에, Rect, Circle 외에도 추가로 "문자열" 관리하는 클래스도 필요하다.
// 그런데, 예전 부터 가지고 있는 "TextView" 를 여기에 사용할수 있을까 ?
// => 안된다. 인터페이스(함수이름)가 다르다.

// 도형편집기 요구 조건 : Shape 로 부터 파생되어야 하고, draw() 함수 필요
// TextView            : Shape 로 부터 파생되지 않았고, show() 함수 제공

// TextView 의 인터페이스(함수이름)을 변경해서 도형편집기에서 사용할수 있게 해보자

class Text : public TextView,   // TextView 로 부터 문자열 관리/출력 기능
			 public Shape		// 도형편집기 시스템 요구조건
{
public:
	Text(const std::string& s) : TextView(s) {}

	// 아래 코드가 "show" 라는 인터페이스(함수이름) 을 "draw" 로 변경하는 코드입니다.
	void draw() override
	{
		TextView::show();
	}
};
// 결국 Text 는 TextView 의 모든 기능을 사용가능한데.
// 도형 편집기에서 사용가능하도록 "인터페이스를 변경" 한것 입니다.
// Adapter 패턴 : 인터페이스의 불일치를 해결하는 패턴.

int main()
{
	std::vector<Shape*> v;

	v.push_back(new Text("hello"));
	v[0]->draw();
}

// 위 예제에서 "Text" 가
// "TextView" 와 "도형편집기" 시스템 사이의 
// 인터페이스의 불일치를 해결하기 위해서 만든 "Adapter" 입니다.







