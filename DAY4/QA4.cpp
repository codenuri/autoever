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

// 도형이 가져야 하는 규칙을 제공하는 기반 클래스를
// "CRTP" 로 만들어 봅시다.

class Shape {};

template<int N, typename T> class Register
{
public:
	static Shape* create() { return new T; }
//	static AutoRegister ar;

	inline static AutoRegister ar{ "AA" }; // ar{N, &T::create}; 
};
//template<typename T> AutoRegister Register<T>::ar("A");

class Rect : public Register<1, Rect>
{
};

int main()
{
//	Rect rc;
//	rc.ar;
}

