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

template<typename T> class lock_free_stack
{
	Node<T>* head = 0;
public:
	void push(const T& data)
	{

	}
};

int main()
{
	lock_free_stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
}