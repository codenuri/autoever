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

template<typename T> class Register
{
public:
	static Shape* create() { return new T; }
	static AutoRegister ar;
};
template<typename T> AutoRegister Register<T>::ar("A");

class Rect : public Register<Rect>
{
};

int main()
{

}

