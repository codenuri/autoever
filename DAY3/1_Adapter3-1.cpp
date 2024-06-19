#include <iostream>
#include <list>
#include <vector>
#include <deque>

// ���� ������ : ��� Ŭ������ ���� ����� ������ ����� ���� ������ 
//              ����ϱ� ���� ���(Ȯ���ϴ� ���� �ȵ�.)

// private ��� : ��� Ŭ������ ��� ����� private �������� ���.
// 
// => ������ ���������� ( �Ļ� Ŭ������ ���������δ� ���������)
//    �������̽��� �������� �ʰڴ�.( �ܺο��� �������� �ʰڴٴ� �ǹ�)

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

	s.push_front(20); // error. push_front�� private ���
}