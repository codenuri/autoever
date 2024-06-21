#include <iostream>
#include <list>
#include <vector>

// #1. �湮�� �������̽� - ��� �湮��Ŭ������ ���Ѿ��ϴ� ��Ģ
template<typename T>
struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// #2. �湮�� ���(���հ�ü, �����̳�)�� �������̽�
template<typename T> 
struct ICollection
{
	virtual void accept(IVisitor<T>* v) = 0;
	virtual ~ICollection() {}
};
//-------------------------------------------------



int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;
	s.accept(&tv);		 

	ShowVisitor<int> sv; 
	s.accept(&sv);


}





