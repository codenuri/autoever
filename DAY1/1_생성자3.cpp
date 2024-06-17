// 1_생성자2.cpp
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
	Person p1("kim", 20); // ok. 초기화된 객체. 안전하다.

//	Person p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
				// => 위험하다.. 버그의 원인..
}


