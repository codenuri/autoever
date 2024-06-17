#include <iostream>

// PC 와 USB 메모리는 "OCP" 를 만족합니다.
// => PC 와 USB 사이에 지켜야 하는 규칙 이 있기 때문에 가능합니다.
// => H/W 는 대부분 OCP 를 만족합니다.

// S/W 설계에서도 "규칙(인터페이스)" 를 먼저 설계 하는 것이 좋습니다.



// 모든 카메라가 지켜야 하는 규칙을 먼저 설계
// 규칙 : 모든 카메라는 아래 클래스로 부터 파생 되어야 한다.

class ICamera
{
public:
	virtual void take() = 0;
};

// 이제 실제 카메라는 없어도, 규칙이 있습니다.
// 사용자는 규칙 대로만 사용하면 됩니다.

class People
{
public:
	// 핵심 ; Camera, HDCamera 등의 구체적인 제품에 의존하지 말고!!
	//        규칙(인터페이스)에 의존해서 사용합니다. (DIP 개념)
	void use_camera(ICamera* c) { c->take(); }
};

// 이제 "카메라를 만들때는 반드시 규칙"을 지켜야 합니다.
class Camera : public ICamera
{
public:
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc);

	UHDCamera uhc;
	p.use_camera(&uhc); // ok!!! 새로운 카메라를 사용하지만
						// People 은 수정될 필요 없다.
}






