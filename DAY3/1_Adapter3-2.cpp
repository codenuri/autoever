#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 상속대신 포함을 사용한 adapter
template<typename T> class stack 
{
	std::list<T> c;
public:
	void push(const T& e) { c.push_back(e); }
	void pop()			  { c.pop_back(); }
	T& top()              { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(20); // error. push_front 라는 멤버 함수는 없다.
}

// list => stack 만들때

// public 상속을 사용 : list 의 모든 함수를 stack 객체도 외부에 노출하겠다는 의도
//						=> 좋지 않은 디자인

// private 상속을 사용 : list 의 모든 함수는 stack 내부적으로만 사용
//						list 의 가상함수가 있다면 stack 에서 override 가능

// 포함을 사용 : list 의 모든 함수는 stack 내부적으로만 사용
// 				list 의 가상함수를 override 할수 있는 능력은 없다.


// java 의 stack : vector 로 부터 public 상속되었습니다.
//				   "나쁜 디자인의 예" 로 널리 알려져 있습니다.