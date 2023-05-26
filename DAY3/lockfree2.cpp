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

// 버전 2. mutex 대신 CPU 명령으로 해결(lock-free)

template<typename T> class lock_free_stack
{
	std::atomic<Node<T>*> head = 0;
public:
	void push(const T& data)
	{
		Node<T>* node = new Node<T>(data);
		
		node->next = head;

		// 이제 head = node->next 만하면 되는데..
		// 그사이에 새로운 스레드가 Node를 만들었다면 ?

		while (!head.compare_exchange_weak(node->next, node));

		// CAS : Compare And Swap 
		// A.CAS(B, C)
		// if ( A == B ) 
		// {
		// 		A = C;
		//		return true;
		// }
		// else 
		// {
		//		B = A;
		//	    return false;
		// }
		
	}
};





lock_free_stack<int> s; 


int main()
{

	s.push(10);
	s.push(20);
	s.push(30);
}