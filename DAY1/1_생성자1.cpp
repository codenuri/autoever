//생성자1.cpp - 3page
#include <iostream>

class Base
{
public:
	Base()     { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:	

	// 파생 클래스 작성시 "기반 클래스 생성자를 호출하는 코드를 작성해야 합니다."
	// 사용자가 작성하지 않으면 컴파일러가 코드를 추가하게 됩니다.

	// 사용자 코드			// 컴파일러가 변경한 코드
	Derived()				// Derived() : Base() 
	{ 
		std::cout << "Derived()" << std::endl; 
	}

	Derived(int a)			// Derived(int a) : Base()   <= 핵심. 컴파일러가 
	{													// 추가한 코드는
														// 항상 디폴트생성자 호출
		std::cout << "Derived(int)" << std::endl; 
	}

	~Derived()		
	{ 
		std::cout << "~Derived()" << std::endl; 

		// 소멸자는 "Derived 의 구현부가 먼저 실행된후, 마지막 단계로 Base 소멸자호출"
		// Base::~Base()	
	}
};
int main()
{
	Derived d1;
//	Derived d2(5);

}