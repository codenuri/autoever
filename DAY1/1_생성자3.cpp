// 1_������2.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	Person(const std::string& name, int age) : name(name), age(age) {}
};

// 1. Person ���� ���� �Ļ��� "Student" Ŭ���� ����� ������
// 2. "int id" ��� �߰��ϼ���
// 3. Student �� ������ �����ؼ� id �ʱ�ȭ �ϼ���
// 4. main ���� Student ��ü ������ ������

class Student : public Person
{

};


int main()
{
	Person p1("kim", 20); // ok. �ʱ�ȭ�� ��ü. �����ϴ�.

//	Person p1;	// �̷��� ��ü�� ����� �ִٴ� ���� ������� ? (�ʱ�ȭ ���� ���� ��ü)
				// => �����ϴ�.. ������ ����..
}


