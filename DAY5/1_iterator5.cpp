#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// C++ STL
// => 함수 이름을 인터페이스로 약속하지 말고
// => "문서화"로 약속 
// => 구현시 "가상함수"가 아닌 "인라인" 함수로 구현

//======================================================

template<typename T>
class slist_iterator 
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {}

	// 요소의 이동과 접근을 "raw pointer" 와 동일하게!!! - 연산자 재정의
	inline slist_iterator<T>& operator++()
	{
		current = current->next;
		return *this;
	}
	
	// ++ : 이동만
	// *  : 요소 접근, 즉 "raw pointer" 와 동일한 사용법.
	inline T& operator*()
	{
		return current->data;
	}
	
	// == ,!= 로 상등연산도 가능하게
	inline bool operator==(const slist_iterator& it) { return current == it.current; }
	inline bool operator!=(const slist_iterator& it) { return current != it.current; }
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
	s.push_front(40); // 40 - 30 - 20 - 10

	// 컨테이너(컬렉션)에서 반복자를 꺼내서 모든 요소를 접근하면 됩니다.
	Iterator<int>* it = s.iterator();

	while (it->hasNext())
	{
		std::cout << it->next() << std::endl;
	}

	delete it; // 라이브러리 내부에서 new 했는데, 사용자가 delete ??
	// 좋지 않은 디자인!!	
	 // 차라리, 스마트 포인터를 사용하는것이 좋습니다.
}

// 위 코드가 Java, C#, Python 등에서 볼수 있는 전통적인 디자인 기법을
// 사용하는 반복자 입니다.

// C++ 언어 관점에서 단점이 있습니다.

// #1. s.iterator()가 반환한 반복자 객체는 "new" 로 생성되었습니다.
//     사용후에는 반드시 "delete" 해야 합니다.

// #2. 다음 요소로 이동하는 next(), hasNext() 등의 함수가
//     "가상함수" 입니다. 성능이 좋지 않습니다. (실행시간에 호출결정)
//	   반복자는 루프 안에서 수백~수천번 이동하기도 합니다.
// 
// #3. "Raw Array" 도 컨테이너입니다.
//      배열은 포인터로 1번째 요소를 가리키고 
//      다음요소로 이동할때 ++, * 를 사용합니다.

//      즉, next() 를 사용하지 않습니다.
//      "모든 컨테이너를 동일한 방식" 으로 한다는 규칙에 맞지 않습니다