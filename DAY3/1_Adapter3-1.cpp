#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 접근 변경자 : 기반 클래스로 부터 상속을 받을때 멤버의 접근 권한을 
//              축소하기 위해 사용(확대하는 것은 안됨.)

// private 상속 : 기반 클래스의 모든 멤버를 private 영역으로 상속.
// 
// => 구현은 물려받지만 ( 파생 클래스가 내부적으로는 사용하지만)
//    인터페이스는 물려받지 않겠다.( 외부에는 노출하지 않겠다는 의미)

template<typename T> class stack : private std::list<T>
{
public:
	void push(const T& e) { std::list<T>::push_back(e); }
	void pop()			  { std::list<T>::pop_back(); }
	T& top()			  { return std::list<T>::back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(20); // error. push_front는 private 멤버
}