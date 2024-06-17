#include <iostream>


// ��� Ŭ���� �Ҹ��ڸ� virtual �ϴ� ������ �Ʒ� �ڵ� �����Դϴ�.
// Base* p = new Derived;
// delete p; // �� �ڵ� ������ 

// �׷���, �����Լ��� ����ϸ�
// 1. �����Լ� ���̺� ���� �޸� ����
// 2. �׸���, �����Լ��� �����ϴ�.

// ���� �Ʒ� �� ���� �ڵ带 ������� �ʴ´ٸ�
// Base* p = new Derived;
// delete p; // �̷� �ڵ� ������� ����.

// �Ҹ��ڸ� virtual �� ���� �ʾƵ� �˴ϴ�.


// �̷� ���� "�����ϰ� �ϱ� ����" 
// => protected non-virtual �Ҹ��ڷ� �ϼ���

class Base
{
protected:
	~Base() {}	// ���� �Ҹ���
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
	Base* p = new Derived;
	delete p;

}
