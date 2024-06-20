#include <iostream>
#include <string>

class AutoRegister
{
public:
	AutoRegister(const std::string& name)
	{
		std::cout << name << " ������\n";
	}
};

// ������ ������ �ϴ� ��Ģ�� �����ϴ� ��� Ŭ������
// "CRTP" �� ����� ���ô�.

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

