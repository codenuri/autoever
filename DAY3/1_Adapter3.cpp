#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter
// 1. C++ 표준에는 list, vector, deque 가 있습니다.
// 2. 그런데, 사용자가 stack 을 요구합니다

// list 의 함수이름을 변경해서 stack 처럼 보이게 해 봅시다.

template<typename T> class stack : public std::list<T>
{
public:
	// 결국 아래 3개 함수는 "list 의 함수 이름을 stack 처럼 보이게 변경"한것
	void push(const T& e) { std::list<T>::push_back( e ); }
	void pop()            { std::list<T>::pop_back(); }

	T&   top()            { return std::list<T>::back();}
};

int main()
{
	stack<int> s;
	s.push(10);

	// 위 구현의 문제점.. 
	// stack 사용자가 아래 처럼 사용할수 있게 됩니다.
	s.push_front(20); // !!!!! 뒤로만 사용해야 하는데.. 앞으로 접근..
					  // 해결책은 다음소스
}