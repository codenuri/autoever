#include <iostream>

class Animal
{
public:
	// non-virtual : �Լ� ȣ��� static binding �϶�� �ǹ�(����Ʈ ���ε���å)
	// => ������ �ð��� ������ Ÿ������ ����
	void cry1() { std::cout << "Animal Cry1" << std::endl; }


	// virtual :  �Լ� ȣ��� dynamic binding �ش޶�� �ǹ�
	// => ����� �޸� ������ ȣ��
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; }
};

class Dog : public Animal
{
public:
	void cry1()         { std::cout << "Dog Cry1" << std::endl; }
	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; }
};

int main()
{
	Dog d;    

	Animal* p = &d;

	p->cry1();	// static binding.  Animal Cry1    call Animal::cry1
	p->cry2();  // dynamic binding  Dog Cry2	   �޸� �����ϴ� ���� �ڵ�
				//									call �������� �����Լ�
}
