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
	// A �� Ŭ���� �Դϴ�. A::ar �����ڴ� �׻� ȣ��˴ϴ�.
	// 
	// B �� Ŭ������ �ƴմϴ�. Ŭ������ �����ϴ� Ʋ �Դϴ�.
	// => B �� ������� ������ Ŭ���� ��ü�� �������� �ʽ��ϴ�.
	// => B::ar ������ ȣ�� �ȵ˴ϴ�.

	// ����, �Ʒ�ó�� B �� ����ؼ� ��ü�� ����� ar �� ȣ��˴ϴ�.
	// ���ø��� "��ü�� �����ϴ� �ڵ尡 �ѹ��� �־�� ar �� �����ڰ� ȣ��˴ϴ�."
	B<int> b;	
}

