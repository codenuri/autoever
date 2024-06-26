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

template<typename T>
class ZeroVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { e = 0; }
};

// C++ STL 은 방문자 패턴을 사용하고 있지 않습니다.
// list 를 확장(상속)해서 방문자 패턴을 적용해 봅시다

template<typename T>
class MyList : public std::list<T>, public ICollection<T>
{
public:
	// C++문법 : 생성자는 기본적으로 상속되지 않습니다.
	//           C++11 부터 아래처럼 하면 "생성자도 상속" 됩니다.
	using std::list<T>::list;

	// => 이제 MyList 객체 생성시 std::list 와 동일한 모양으로 생성가능합니다.


	void accept(IVisitor<T>* v) override
	{
		// 방문자는 요소 한개에 적용할 연산을 가지고 있습니다.
		// 자신의 모든 요소를 방문자에게 전달합니다
		for (auto& e : *this)  // *this 는 list 입니다. !!
			v->visit(e);
	}
};

int main()
{
	// MyList<int> s1(10, 3);
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;
	s.accept(&tv);		 

	ShowVisitor<int> sv; 
	s.accept(&sv);

	ZeroVisitor<T> zv; // 방문하는 요소를 0으로 만드는 방문자
	s.accept(&zv);

	s.accept(&sv); // 화면 출력
}

// 위 예제는 실용적이지는 않습니다. 
// => 그냥 직접 요소를 2배로 하면 됩니다
// => 설명을 위한 예제
// 
// => 다음예제가 더 좋습니다



