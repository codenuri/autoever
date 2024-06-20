#include <iostream>
#include <string>

class AutoRegister
{
public:
	AutoRegister(const std::string& name) 
	{ 
		std::cout << name << " 공장등록\n"; 
	}
};

struct A
{
	inline static AutoRegister ar{"A"};
};

template<typename T>
struct B
{
	inline static AutoRegister ar{ "B" };
};

int main()
{
	// A 는 클래스 입니다. A::ar 생성자는 항상 호출됩니다.
	// 
	// B 는 클래스가 아닙니다. 클래스를 생성하는 틀 입니다.
	// => B 를 사용하지 않으면 클래스 자체가 생성되지 않습니다.
	// => B::ar 생성자 호출 안됩니다.

	// 또한, 아래처럼 B 를 사용해서 객체를 만들면 ar 이 호출됩니다.
	// 템플릿은 "객체를 생성하는 코드가 한번은 있어야 ar 의 생성자가 호출됩니다."
	B<int> b;	
}

