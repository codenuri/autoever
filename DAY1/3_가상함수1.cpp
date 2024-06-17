#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal Cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	// function override 
	void cry() { std::cout << "Dog Cry" << std::endl; } 
};

int main()
{
	Animal a; a.cry(); // "Animal Cry"
	Dog d;    d.cry(); // "Dog Cry"

	Animal* p = &d; 

	p->cry();	// ��� �Լ��� ȣ���Ұ��ΰ� ?
				// C++/C# : Animal Cry
				// Java/Swift/Python/Kotlin/Objective-C : Dog Cry 
}		

// "p->cry()" �� ��� �Լ��� ������ ���ΰ� ??
// => �Լ� ���ε�(function binding) �̶�� �մϴ�.
// => 2���� ���ε��� �ֽ��ϴ�.(C++ �� �ƴ϶� ��� ���� ���Ǵ� �Ϲ����� �̷�)

// �ٽ� : �����Ϸ��� "p�� ����Ű�� �޸𸮿� �ִ� ��ü�� ����"�� �����Ҽ� ����.
//        => ����ð��� ����ɼ� �����Ƿ�

// 1. static binding : �����Ϸ��� ������ �ð��� �Լ� ȣ���� ����
//					   �����Ϸ��� ���� ��ü�� ������ �����Ҽ� �����Ƿ�
//						������ ������ Ÿ��(Animal* p) ���� �Լ� ����
//						"Animal Cry" ȣ��
// ��������, �������� �ʴ�.
// C++, C# �� �⺻ ���ε�


// 2. dynamic binding : ������ �ð����� "p�� ����Ű�� �޸𸮴� �����ϴ� ���� ����"
//					    ����ð��� �޸� ������ �Լ� ����
//					    ���� ��ü�� "Dog" ���ٸ�
//						"Dog Cry" ȣ��
// ��������, �����̴�.
// java, swift, python, objective-c ���� ��κ��� ��ü���� ���
// C++, C# �� virtual function

// C++, C# : static binding �� dynamic binding �� ��� ����
// java    : dynamic binding �� ����