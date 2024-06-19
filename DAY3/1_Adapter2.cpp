#include <iostream>
#include <string>
#include <vector>

class TextView
{

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

// Adapter 의 종류
// 클래스 어답터 : 클래스의 인터페이스를 변경하는 것
// 객체   어답터 : 객체의   인터페이스를 변경하는 것

class Text : public TextView, public Shape		
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() override
	{
		TextView::show();
	}
};





int main()
{
	std::vector<Shape*> v;

	TextView tv("hello");	// TextView : 클래스
							// tv       : 객체

	// 이미 생성된 TextView 타입의 "객체 tv" 를 도형편집기 시스템에 넣을수 있을까 ?
	v.push_back( &tv );	// error. Shape 로 부터 파생되지 않았다
						
	// Text 를 사용할수도 없다!!
	// tv를 도형편집기(v) 에 넣으려면 "객체 어답터" 필요!!
}





