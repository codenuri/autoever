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
// �ٽ� : �湮�ڸ� �ᱹ "��� �Ѱ��� ���� ������ ����" �ϴ� Ŭ���� �Դϴ�.

template<typename T> 
class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { e = e * 2; }
};

template<typename T>
class ShowVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { std::cout << e << ", "; }
};

// C++ STL �� �湮�� ������ ����ϰ� ���� �ʽ��ϴ�.
// list �� Ȯ��(���)�ؼ� �湮�� ������ ������ ���ô�

template<typename T>
class MyList : public std::list<T>, public ICollection<T>
{
public:
	void accept(IVisitor<T>* v) override
	{
		// �湮�ڴ� ��� �Ѱ��� ������ ������ ������ �ֽ��ϴ�.
		// �ڽ��� ��� ��Ҹ� �湮�ڿ��� �����մϴ�
		for (auto& e : *this)
			v->visit(e);
	}
};






int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;
	s.accept(&tv);		 

	ShowVisitor<int> sv; 
	s.accept(&sv);


}





