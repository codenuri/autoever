#include <iostream>

class Base
{
public:
	~Base() {}
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

}	
