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

	p->cry();	// 어느 함수를 호출할것인가 ?
				// C++/C# : Animal Cry
				// Java/Swift/Python/Kotlin/Objective-C : Dog Cry 
}		

// "p->cry()" 를 어느 함수와 연결할 것인가 ??
// => 함수 바인딩(function binding) 이라고 합니다.
// => 2개의 바인딩이 있습니다.(C++ 뿐 아니라 모든 언어에서 사용되는 일반적인 이론)

// 핵심 : 컴파일러는 "p가 가리키는 메모리에 있는 객체의 종류"를 조사할수 없다.
//        => 실행시간에 변경될수 있으므로

// 1. static binding : 컴파일러가 컴파일 시간에 함수 호출을 결정
//					   컴파일러는 실제 객체의 종류를 조사할수 없으므로
//						무조건 포인터 타입(Animal* p) 으로 함수 결정
//						"Animal Cry" 호출
// 빠르지만, 논리적이지 않다.
// C++, C# 의 기본 바인딩


// 2. dynamic binding : 컴파일 시간에는 "p가 가리키는 메모리는 조사하는 기계어 생성"
//					    실행시간에 메모리 조사후 함수 결정
//					    실제 객체가 "Dog" 였다면
//						"Dog Cry" 호출
// 느리지만, 논리적이다.
// java, swift, python, objective-c 등의 대부분의 객체지향 언어
// C++, C# 의 virtual function

// C++, C# : static binding 과 dynamic binding 이 모두 가능
// java    : dynamic binding 만 가능