#include <iostream>
#include <list>
#include <vector>
#include <deque>

// Adapter �������� ����� stack ��
// "Policy Base Design" �� ������ ���ô�.

template<typename T,  // ������ Ÿ��
	     typename C = std::deque<T> > // ���ο��� ����� �����̳�
class stack
{
	C c;
public:
	void push(const T& e) { c.push_back(e); }
	void pop()			  { c.pop_back(); }
	T& top() { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

	stack<int, std::list<int>>   s1;
	stack<int, std::vector<int>> s2;

}

