#include <iostream>
#include <list>
#include <vector>

// visitor 패턴
// 
// 반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 열거
// 방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 연산수행


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.
	// #1. 모든 요소를 직접 열거하면서 2배로 !!
	for (auto& e : s)
	{
		e = e * 2;
	}

	// #2. 방문자 패턴을 사용!!
	TwiceVisitor<int> tv; // 방문하는 요소를 2배로 하는 방문자 객체
	s.accept(&tv);		  // 복합객체 s 에 tv 가 방문

	ShowVisitor<int> sv;  // 방문하는 요소를 화면에 출력하는 방문자
	s.accept(&sv);

	// 위 코드를 보고 알수 있는것!!
	// #1. 모든 컨테이너(컬렉션)는 방문자를 받아들이는 accept 가 있어야 한다.
	// => 컨테이너의 인터페이스로 약속!!

	// #2. accept 는 다양한 방문자를 받을수 있어야 한다.
	// => 방문자 인터페이스(IVisitor) 필요
	// => accept(IVisitor*) 처럼 만든다는 것.
}





