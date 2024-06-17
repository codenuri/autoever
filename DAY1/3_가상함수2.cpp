#include <iostream>

// �ٽ�
// ��� Ŭ������ �Ҹ��ڴ� �ݵ�� "virtual" �̾�� �Ѵ�. "����Ҹ��� ����"
// ��, virtual �� ���� �������� "protected"�� ���ƾ� �Ѵ�.

class Base
{
public:
//	~Base() {}
	virtual ~Base() {}	// ���� �Ҹ���
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

	// 
	// "delete p" ���� �Ҹ��ڸ� ȣ���ؾ� �մϴ�.
	// "�Ҹ��� ȣ��" �� �ᱹ "�Լ��� ȣ��" �Դϴ�.

	// 1. p �� Ÿ���� Base* �̹Ƿ� Base Ŭ������ �����ؼ�
	//    �Ҹ��ڰ� virtual ���� �ƴ����� ���� �����մϴ�.

	// 2. �Ҹ��ڰ� virtual     : dynamic binding
	//							=> ����ð��� p�� ����Ű�� �޸� ������
	//							=> �Ҹ��� ����
	// 
	// 3. �Ҹ��ڰ� non-virtual : static  binding
	//							=> ������ Ÿ������ �Ҹ��� ����
	//							=> p�� Base* �̹Ƿ� ~Base() �� ȣ��
}	
