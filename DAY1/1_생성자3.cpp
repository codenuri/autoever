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

// 1. Person 으로 부터 파생된 "Student" 클래스 만들어 보세요
// 2. "int id" 멤버 추가하세요
// 3. Student 에 생성자 제공해서 id 초기화 하세요
// 4. main 에서 Student 객체 생성해 보세요

class Student : public Person
{
	int id;
public:
	// 아래 처럼 만들면 오른쪽 주석 처럼 컴파일러가 추가한 코드 때문에 에러
	// => Person 에 디폴트 생성자가 없습니다.
//	Student(int id) : id(id) {} // Student(int id) : Person(), id(id) {}

	// 해결책
	// => Student 제작자는 Person 에 디폴트 생성자가 없다는 것을 알아야 합니다.
	// => Student 생성자에서 Person 의 다른 생성자를 명시적으로 호출해야합니다.
	
	Student(const std::string& name, int age, int id) 
		: Person( name, age ),  id(id) {}
};

int main()
{
	Student s("kim", 20, 15);

	Person p1("kim", 20); // ok. 초기화된 객체. 안전하다.

//	Person p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
				// => 위험하다.. 버그의 원인..
}


