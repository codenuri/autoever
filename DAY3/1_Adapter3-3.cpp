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
	inline void push(const T& e)  { c.push_back(e); }
	inline void pop()			  { c.pop_back(); }
	inline T& top()				  { return c.back(); }
};

#include <stack> // C++ 표준의 stack. 
				 // => 위처럼 구현되어 있습니다.
				 // => 흔히 "stack adapter" 라고 부릅니다.

int main()
{
	stack<int> s;
	s.push(10);

	stack<int, std::list<int>>   s1;
	stack<int, std::vector<int>> s2;

}

