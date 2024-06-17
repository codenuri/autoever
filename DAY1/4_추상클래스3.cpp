#include <iostream>

// PC 와 USB 메모리는 "OCP" 를 만족합니다.
// => PC 와 USB 사이에 지켜야 하는 규칙 이 있기 때문에 가능합니다.
// => H/W 는 대부분 OCP 를 만족합니다.

// S/W 설계에서도 "규칙(인터페이스)" 를 먼저 설계 하는 것이 좋습니다.


// 추상클래스 vs 인터페이스
// 인터 페이스 : 지켜야 하는 규칙만 가진 경우
// 추상 클래스 : 지켜야 하는 규칙만 가진 경우 +  다른 멤버도 있는 경우

// java, C# : abstract, interface 라는 별도의 키워드 존재
// C++      : 별도의 키워드 없고, 추상 클래스 문법으로 모두 만듬..
//             단지, 위의 특징으로 개념적으로만 구분..

// 모든 카메라가 지켜야 하는 규칙을 먼저 설계
// 규칙 : "모든 카메라는 아래 클래스로 부터 파생 되어야 한다." 라고 표현하지 말고
//        "모든 카메라는 아래 인터페이스를 구현 해야 한다." 라고 표현하는 것이 좋습니다.

//class ICamera		// 접근지정자를 생략하면 private
struct ICamera		// 접근지정자를 생략하면 public
{	
//public:
	virtual void take() = 0;
	virtual ~ICamera() {}   // 인터페이스는 결국 문법적으로는 기반 클래스입니다.
							// C++에서 기반 클래스의 소멸자는 "virtual" 이어야 합니다.
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


// 강한 결합(tightly coupling)
// => People 이 카메라 사용시, "구체적인 제품이름(Camera, HDCamera 등의 클래스이름)를 사용하는것"
// => People::use_camera(HDCamera*)
// => 교체 불가능한 경직된 디자인


// 약한 결합(loosely coupling)
// => People 이 카메라 사용시, "구체적인 제품이름(Camera, HDCamera 등의 클래스이름)"
//    이 아닌 "규칙(인터페이스)의 이름(ICamera)" 를 사용하는 것
// 
// => People::use_camera(ICamera*)
// => 교체 가능한 유연한 디자인 - 좋은 설계!!!
// 
// => 그런데.. 성능은!! => 가상함수를 사용하게 되므로 느리다.!!
//    C++은 다양한 테크닉을 사용해서 해결하기 위해 노력!! - 내일부터 등장




