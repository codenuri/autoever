#include <iostream>
#include <list>
#include <vector>
#include <deque>

// ��Ӵ�� ������ ����� adapter
template<typename T> class stack 
{
	std::list<T> c;
public:
	void push(const T& e) { c.push_back(e); }
	void pop()			  { c.pop_back(); }
	T& top()              { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(20); // error. push_front ��� ��� �Լ��� ����.
}

// list => stack ���鶧

// public ����� ��� : list �� ��� �Լ��� stack ��ü�� �ܺο� �����ϰڴٴ� �ǵ�
//						=> ���� ���� ������

// private ����� ��� : list �� ��� �Լ��� stack ���������θ� ���
//						list �� �����Լ��� �ִٸ� stack ���� override ����

// ������ ��� : list �� ��� �Լ��� stack ���������θ� ���
// 				list �� �����Լ��� override �Ҽ� �ִ� �ɷ��� ����.


// java �� stack : vector �� ���� public ��ӵǾ����ϴ�.
//				   "���� �������� ��" �� �θ� �˷��� �ֽ��ϴ�.