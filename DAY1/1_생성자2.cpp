#include <iostream>

class Base
{
public:
//	Base() { }
	Base(int a) { }
	~Base()		{ }
};

// �Ʒ� �ڵ忡�� ������ ��� ã������
// => �ٽ��� "Base �� ����Ʈ �����ڰ� ����"�� �� �Դϴ�.
class Derived : public Base
{
public:
	// ����� �ڵ�			// �����Ϸ��� ������ �ڵ�
//	Derived()		{}		// Derived()      : Base() {}	
//	Derived(int a)	{}		// Derived(int a) : Base() {}	

	// �ٽ� : ��� Ŭ������ ����Ʈ �����ڰ� ���ٸ�
	//		  �Ļ� Ŭ������ �����ڿ��� ��� Ŭ������ �ٸ� �����ڸ�
	//        ��������� ȣ���ؾ� �մϴ�.

	Derived()      : Base(0) {}
	Derived(int a) : Base(a) {}

	~Derived()		{}
};


int main()
{
	Derived d1;
	//	Derived d2(5);

}