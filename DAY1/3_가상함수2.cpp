#include <iostream>

// 핵심
// 기반 클래스의 소멸자는 반드시 "virtual" 이어야 한다. "가상소멸자 문법"
// 단, virtual 로 하지 않으려면 "protected"에 놓아야 한다.

class Base
{
public:
//	~Base() {}
	virtual ~Base() {}	// 가상 소멸자
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
//	Derived d;		// 아무 문제 없음.

//	Derived* p = new Derived;	// 생성자 호출
//	delete p;					// 소멸자 호출 -  아무 문제 없음.


	// 핵심 : 아래 코드의 경우를 생각해 보세요
	Base* p = new Derived;
	delete p;

	// 
	// "delete p" 에서 소멸자를 호출해야 합니다.
	// "소멸자 호출" 도 결국 "함수의 호출" 입니다.

	// 1. p 의 타입이 Base* 이므로 Base 클래스를 조사해서
	//    소멸자가 virtual 인지 아닌지를 먼저 조사합니다.

	// 2. 소멸자가 virtual     : dynamic binding
	//							=> 실행시간에 p가 가리키는 메모리 조사후
	//							=> 소멸자 결정
	// 
	// 3. 소멸자가 non-virtual : static  binding
	//							=> 포인터 타입으로 소멸자 결정
	//							=> p가 Base* 이므로 ~Base() 만 호출
}	
