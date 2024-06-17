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
	~Base() {}	// non-virtual �Ҹ���
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
	delete p;	// �̼��� Base �Ҹ��� ȣ���ؾ� �ϴµ�
				// protected ����� �ܺο��� ���� �ȵǹǷ�
				// error. ��, �̷��Դ� ����Ҽ� ����.

	Derived* p2 = new Derived;
	delete p2;  // ok.. ~Derived() �ȿ��� ~Base() ȣ���ϹǷ�!!
				// �Ļ� Ŭ������ ��� Ŭ���� protected ���� ����.
}

// ���� 
// 1. ����� ����Ѵٸ�, ������ ��� Ŭ������ �Ҹ��ڴ� virtual �� �ϼ���..!!
// 2. �� ������ �Ϻ��� ���� �ǽźи� �� ����� ����� ������

// ���ۿ��� "C++ core guideline" �˻��� 1��° ��ũ
