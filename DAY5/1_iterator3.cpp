#include <iostream>
#include <vector>
#include <list>

// 아래 코드는 "Java 언어" 의 반복자 코드 입니다.
// => 컴파일 되지는 않습니다. 설명을 위한 코드

int main()
{
	slist<int>  s = { 1,2,3 };
	vector<int> v = { 1,2,3 };

	// 규칙 #1. 모든 컨테이너(컬렉션)에서는 반복자를 꺼내는 iterator() 함수가 있습니다.
	// => 인터페이스로 규칙을 설계.
	auto it1 = s.iterator();
	auto it2 = v.iterator();

	// 규칙 #2. 모든 반복자는 사용법이 동일해야 합니다
	// => hasNext(), next() 멤버 함수가 있어야 합니다.
	// => 모든 반복자가 지켜야 하는 규칙을 "인터페이스"로 설계

	while (it1.hasNext())
	{
		std::cout << it1.next() << std::endl;
	}

	while (it2.hasNext())
	{
		std::cout << it2.next() << std::endl;
	}
}

