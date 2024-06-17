#include <iostream>


// 기반 클래스 소멸자를 virtual 하는 이유는 아래 코드 때문입니다.
// Base* p = new Derived;
// delete p; // 이 코드 때문에 

// 그런데, 가상함수를 사용하면
// 1. 가상함수 테이블에 의한 메모리 낭비
// 2. 그리고, 가상함수는 느립니다.

// 만일 아래 와 같은 코드를 사용하지 않는다면
// Base* p = new Derived;
// delete p; // 이런 코드 사용하지 않음.

// 소멸자를 virtual 로 하지 않아도 됩니다.


// 이런 경우는 "안전하게 하기 위해" 
// => protected non-virtual 소멸자로 하세요

class Base
{
protected:
	~Base() {}	// 가상 소멸자
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
	Base* p = new Derived;
	delete p;

}
