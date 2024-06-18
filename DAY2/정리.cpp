/// 정리.cpp

// 객체지향 디자인 패턴의 핵심 #1. 공통성과 가변성의 분리
// => 공통으로 사용되는 코드(변하지 않는것) 와 사용자가 변경할수 있게하는 코드를 분리

// 1. 변하는 것을 가상함수로    : template method
// 2. 변하는 것을 다른 클래스로 : strategy, policy base design ( C++ IDioms)

// 변하는 것(정책 클래스) 를 교체 하는 2가지 방법

//					interface 기반 교체			template 인자로 교체
// 예제				Edit/IValidator				vector/debug_alloc
// 
// 성능				가상함수이므로 느리다.		가상함수가 아닌 inline. 빠르다.
// 
// 실행시간 교체		가능.						안됨.
//					e.set_validator(정책1)		vector<int, debug_alloc<int>> v;
//					e.set_validator(정책2)		실행시간에 v의 정책을 교체 할수 없다

// 정책클래스의		인터페이스로 약속되어 있다		문서화 되어 있다.
// 함수이름			(함수이름을 코드로 약속)		cppreference.com 의 "Named Requirement"
//												C++20 부터는 코드로도 가능 "concept"