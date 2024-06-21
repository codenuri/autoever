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
	virtual Iterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};
//======================================================
// slist 의 반복자를 만들어 봅시다.
// => 내부적으로 1번째 요소(NODE)에 대한 주소를 가지고 있다고
// => 약속된 방식(next) 로 다음으로 이동할수 있으면 됩니다.
template<typename T>
class slist_iterator : public Iterator<T>
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {}

	// Iterator 인터페이스에서 약속된 규칙을 구현
	T& next() override
	{
		T& tmp = current->data;
		current = current->next;
		return tmp;	 // 1. 자신이 가리키던 요소를 반환하고
					 // 2. 다음으로 이동
	}

	bool hasNext() override
	{
		return current != nullptr;
	}
};

// 모든 컨테이너(컬렉션)은 반복자를 꺼내는 함수가 있어야 한다.
template<typename T> struct slist : public ICollection<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	Iterator<T>* iterator() override
	{
		return new slist_iterator<T>(head);
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40); 

	// 컨테이너(컬렉션)에서 반복자를 꺼내서 모든 요소를 접근하면 됩니다.
	Iterator<int>* it = s.iterator();

	while (it->hasNext())
	{
		std::cout << it->next() << std::endl;
	}
}
