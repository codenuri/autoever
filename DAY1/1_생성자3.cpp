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
	int id;
public:
	// �Ʒ� ó�� ����� ������ �ּ� ó�� �����Ϸ��� �߰��� �ڵ� ������ ����
	// => Person �� ����Ʈ �����ڰ� �����ϴ�.
//	Student(int id) : id(id) {} // Student(int id) : Person(), id(id) {}

	// �ذ�å
	// => Student �����ڴ� Person �� ����Ʈ �����ڰ� ���ٴ� ���� �˾ƾ� �մϴ�.
	// => Student �����ڿ��� Person �� �ٸ� �����ڸ� ��������� ȣ���ؾ��մϴ�.
	
	Student(const std::string& name, int age, int id) 
		: Person( name, age ),  id(id) {}
};

int main()
{
	Student s("kim", 20, 15);

	Person p1("kim", 20); // ok. �ʱ�ȭ�� ��ü. �����ϴ�.

//	Person p1;	// �̷��� ��ü�� ����� �ִٴ� ���� ������� ? (�ʱ�ȭ ���� ���� ��ü)
				// => �����ϴ�.. ������ ����..
}


