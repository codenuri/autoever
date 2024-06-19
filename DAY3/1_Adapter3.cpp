#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL �� Adapter
// 1. C++ ǥ�ؿ��� list, vector, deque �� �ֽ��ϴ�.
// 2. �׷���, ����ڰ� stack �� �䱸�մϴ�

// list �� �Լ��̸��� �����ؼ� stack ó�� ���̰� �� ���ô�.

template<typename T> class stack : public std::list<T>
{
public:
	// �ᱹ �Ʒ� 3�� �Լ��� "list �� �Լ� �̸��� stack ó�� ���̰� ����"�Ѱ�
	void push(const T& e) { std::list<T>::push_back( e ); }
	void pop()            { std::list<T>::pop_back(); }

	T&   top()            { return std::list<T>::back();}
};

int main()
{
	stack<int> s;
	s.push(10);

	// �� ������ ������.. 
	// stack ����ڰ� �Ʒ� ó�� ����Ҽ� �ְ� �˴ϴ�.
	s.push_front(20); // !!!!! �ڷθ� ����ؾ� �ϴµ�.. ������ ����..
					  // �ذ�å�� �����ҽ�
}