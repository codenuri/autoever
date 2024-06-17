//1_추상클래스2.cpp
#include <iostream>


class Camera
{
public:	
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void use_camera(Camera* p) { p->take(); }
	void use_camera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ??
}

// OCP 이론
// 기능 확장에 열려 있고(Open, 새로운 모듈/클래스 가 추가되어도)
// 코드 수정에는 닫혀 있어야(Close, 기존 코드는 수정되지 않도록)
// 만들어야 한다는 이론(Principle)

// Open Close Principle (개방 폐쇄의 법칙)

// 객체 지향 설계시 지켜야 하는 5개 원칙(Principle)
// => SRP, OCP, LSP, ISP, DIP
// => 약자로 "SOLID" 라고 합니다.





