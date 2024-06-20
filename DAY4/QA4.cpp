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
	inline static AutoRegister ar{ "����" };
};

class Rect : public Register<Rect>
{
};

int main()
{

}

