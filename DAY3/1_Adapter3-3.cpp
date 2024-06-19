#include <iostream>
#include <list>
#include <vector>
#include <deque>

// Adapter 패턴으로 설계된 stack 에
// "Policy Base Design" 을 적용해 봅시다.

template<typename T,  // 저장할 타입
	     typename C = std::deque<T> > // 내부에서 사용할 컨테이너
class stack
{
	C c;
public:
	void push(const T& e) { c.push_back(e); }
	void pop()			  { c.pop_back(); }
	T& top() { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

	stack<int, std::list<int>>   s1;
	stack<int, std::vector<int>> s2;

}

