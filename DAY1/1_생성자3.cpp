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

int main()
{
	Person p1("kim", 20); // ok. �ʱ�ȭ�� ��ü. �����ϴ�.

//	Person p1;	// �̷��� ��ü�� ����� �ִٴ� ���� ������� ? (�ʱ�ȭ ���� ���� ��ü)
				// => �����ϴ�.. ������ ����..
}


