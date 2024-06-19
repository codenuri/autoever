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
	inline void push(const T& e)  { c.push_back(e); }
	inline void pop()			  { c.pop_back(); }
	inline T& top()				  { return c.back(); }
};

#include <stack> // C++ ǥ���� stack. 
				 // => ��ó�� �����Ǿ� �ֽ��ϴ�.
				 // => ���� "stack adapter" ��� �θ��ϴ�.

int main()
{
	stack<int> s;
	s.push(10);

	stack<int, std::list<int>>   s1;
	stack<int, std::vector<int>> s2;

}

