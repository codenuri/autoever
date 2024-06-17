#include <iostream>

class Animal
{
public:
	int age;
	virtual ~Animal() {} // 가상 소멸자. 다음시간에 자세히 설명
						 // dynamic_cast 를 사용하려면 한개 이상의 가상함수필요

};

class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Animal a;
	Dog d;

	Animal* p = &d;

//	if (사용자 입력 == 1) p = &a;

	// 핵심 #1. 컴파일시간에 컴파일러는 p가 가리키는 객체의 종류는
	//          알수 없다.(조사할수 없다.)
	// => 위 if 문 같은 코드가 있다면 실행시간에 p가 가리키는 곳이 "변경" 되므로         

	// 핵심 #2. 캐스팅의 종류
	// static_cast  : 컴파일 시간 캐스팅
	// dynamic_cast : 실행   시간 캐스팅

	// #1. static_cast : 컴파일 시간에 캐스팅
	// 장점 : 오버헤드가 전혀 없다. 빠르다.
	// 단점 : 객체를 조사할수 없다.

	p = &a; // p는 Animal 객체를 가리킨다.

	Dog* pdog = static_cast<Dog*>(p);	// 잘못된 캐스팅이지만
										// 조사할수 없으므로 그냥 주소가 나온다

	std::cout << pdog << std::endl; // 주소가 나온다!!
									// 단, 이주소는 사용하면 안됨..	
									// pdog 가 가리키는 곳은 Dog 가 아닌 Animal
	
	// #2. dynamic_cast : 실행시간 캐스팅
	// 특징 : 가상함수가 있는 타입에 대해서만 사용가능.
	//       "실행시간에 타입을 조사하려면 가상함수 테이블이 있어야 한다."
	// 
	// 장점 : 객체의 종류를 조사할수 있다. 잘못된 캐스팅의 경우 0 반환
	// 단점 : "실행시간에 조사" 해야 하므로 오버헤드가 있다. 느리다.

	Dog* pdog2 = dynamic_cast<Dog*>(p); // 현재 "p = &a" 상태 이므로
										// 잘못된 캐스팅
										// 0반환
	std::cout << pdog2 << std::endl;


	// 단, 프로그램에서 "dynamic_cast" 를 사용하는 것은 
	// => 나쁜 디자인 입니다. 오후 수업에서 등장..
	// => 좋은 코드는 "dynamic_cast" 를 사용하면 안됩니다.
}











