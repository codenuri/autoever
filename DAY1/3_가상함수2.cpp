#include <iostream>

class Base
{
public:
	~Base() {}
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
//	Derived d;		// �ƹ� ���� ����.

//	Derived* p = new Derived;	// ������ ȣ��
//	delete p;					// �Ҹ��� ȣ�� -  �ƹ� ���� ����.


	// �ٽ� : �Ʒ� �ڵ��� ��츦 ������ ������
	Base* p = new Derived;
	delete p;

}	
