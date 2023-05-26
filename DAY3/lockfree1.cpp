// lockfree1
#include <atomic>
#include <memory>
#include <iostream>
#include <mutex>

template<typename T> struct Node
{
	T data;
	Node* next;
	Node(const T& data) : data(data) {}
};
// 버전 1. lock-free 가 아닌 뮤텍스로 동기화 하는 코드
// => 스레드에 안전하지만 mutex 를 사용하므로 약간의 오버헤드가 있습니다.
template<typename T> class lock_free_stack
{
	Node<T>* head = 0;
	std::mutex m;
public:
	void push(const T& data)
	{
		Node<T>* node = new Node<T>(data);

		std::lock_guard<std::mutex> g(m);

		node->next = head;
		head = node->next;
	}
};

lock_free_stack<int> s; // 전역변수
						// 멤버 데이타 인 head를 모든 스레드가 공유


int main()
{
//	lock_free_stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
}