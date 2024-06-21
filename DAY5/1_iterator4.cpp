#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};
//----------------------------------------------------
// #1. �ݺ��� �������̽� - ��� �ݺ��ڰ� ���Ѿ� �ϴ� ��Ģ
template<typename T>
struct Iterator
{
	virtual bool hasNext() = 0;
	virtual T& next() = 0;
	virtual ~Iterator() {}
};

// #2. �����̳�(�÷���)�� �������̽� - �ݺ��ڸ� ������ �Լ��� �̸��� ���
template<typename T> 
struct ICollection
{
	virtual Iterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};
//======================================================
// slist �� �ݺ��ڸ� ����� ���ô�.
// => ���������� 1��° ���(NODE)�� ���� �ּҸ� ������ �ִٰ�
// => ��ӵ� ���(next) �� �������� �̵��Ҽ� ������ �˴ϴ�.
template<typename T>
class slist_iterator : public Iterator<T>
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {}

	// Iterator �������̽����� ��ӵ� ��Ģ�� ����
	T& next() override
	{
		T& tmp = current->data;
		current = current->next;
		return tmp;	 // 1. �ڽ��� ����Ű�� ��Ҹ� ��ȯ�ϰ�
					 // 2. �������� �̵�
	}

	bool hasNext() override
	{
		return current != nullptr;
	}
};

// ��� �����̳�(�÷���)�� �ݺ��ڸ� ������ �Լ��� �־�� �Ѵ�.
template<typename T> struct slist : public ICollection<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	Iterator<T>* iterator() override
	{
		return new slist_iterator<T>(head);
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40); 

	// �����̳�(�÷���)���� �ݺ��ڸ� ������ ��� ��Ҹ� �����ϸ� �˴ϴ�.
	Iterator<int>* it = s.iterator();

	while (it->hasNext())
	{
		std::cout << it->next() << std::endl;
	}
}
