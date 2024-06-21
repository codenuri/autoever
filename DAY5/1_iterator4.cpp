#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};
//----------------------------------------------------
// #1. 반복자 인터페이스 - 모든 반복자가 지켜야 하는 규칙
template<typename T>
struct Iterator
{
	virtual bool hasNext() = 0;
	virtual T& next() = 0;
	virtual ~Iterator() {}
};

// #2. 컨테이너(컬렉션)의 인터페이스 - 반복자를 꺼내는 함수의 이름을 약속
template<typename T> 
struct ICollection
{
	virtual Iterator<T> iterator() = 0;
	virtual ~ICollection() {}
};





template<typename T> struct slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40); 
}