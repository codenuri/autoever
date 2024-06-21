#include <iostream>
#include <list>
#include <vector>

// #1. 방문자 인터페이스 - 모든 방문자클래스가 지켜야하는 규칙
template<typename T>
struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// #2. 방문의 대상(복합객체, 컨테이너)의 인터페이스
template<typename T> 
struct ICollection
{
	virtual void accept(IVisitor<T>* v) = 0;
	virtual ~ICollection() {}
};
//-------------------------------------------------
// 핵심 : 방문자를 결국 "요소 한개에 대한 연산을 정의" 하는 클래스 입니다.

template<typename T> 
class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { e = e * 2; }
};

template<typename T>
class ShowVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { std::cout << e << ", "; }
};

// C++ STL 은 방문자 패턴을 사용하고 있지 않습니다.
// list 를 확장(상속)해서 방문자 패턴을 적용해 봅시다

template<typename T>
class MyList : public std::list<T>, public ICollection<T>
{
public:
	void accept(IVisitor<T>* v) override
	{
		// 방문자는 요소 한개에 적용할 연산을 가지고 있습니다.
		// 자신의 모든 요소를 방문자에게 전달합니다
		for (auto& e : *this)
			v->visit(e);
	}
};






int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;
	s.accept(&tv);		 

	ShowVisitor<int> sv; 
	s.accept(&sv);


}





