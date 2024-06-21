#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// C++ STL
// => �Լ� �̸��� �������̽��� ������� ����
// => "����ȭ"�� ��� 
// => ������ "�����Լ�"�� �ƴ� "�ζ���" �Լ��� ����

//======================================================

template<typename T>
class slist_iterator 
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {}

	// ����� �̵��� ������ "raw pointer" �� �����ϰ�!!! - ������ ������
	inline slist_iterator<T>& operator++()
	{
		current = current->next;
		return *this;
	}
	
	// ++ : �̵���
	// *  : ��� ����, �� "raw pointer" �� ������ ����.
	inline T& operator*()
	{
		return current->data;
	}
	
	// == ,!= �� ���굵 �����ϰ�
	inline bool operator==(const slist_iterator& it) { return current == it.current; }
	inline bool operator!=(const slist_iterator& it) { return current != it.current; }
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
	s.push_front(40); // 40 - 30 - 20 - 10

	// �����̳�(�÷���)���� �ݺ��ڸ� ������ ��� ��Ҹ� �����ϸ� �˴ϴ�.
	Iterator<int>* it = s.iterator();

	while (it->hasNext())
	{
		std::cout << it->next() << std::endl;
	}

	delete it; // ���̺귯�� ���ο��� new �ߴµ�, ����ڰ� delete ??
	// ���� ���� ������!!	
	 // ����, ����Ʈ �����͸� ����ϴ°��� �����ϴ�.
}

// �� �ڵ尡 Java, C#, Python ��� ���� �ִ� �������� ������ �����
// ����ϴ� �ݺ��� �Դϴ�.

// C++ ��� �������� ������ �ֽ��ϴ�.

// #1. s.iterator()�� ��ȯ�� �ݺ��� ��ü�� "new" �� �����Ǿ����ϴ�.
//     ����Ŀ��� �ݵ�� "delete" �ؾ� �մϴ�.

// #2. ���� ��ҷ� �̵��ϴ� next(), hasNext() ���� �Լ���
//     "�����Լ�" �Դϴ�. ������ ���� �ʽ��ϴ�. (����ð��� ȣ�����)
//	   �ݺ��ڴ� ���� �ȿ��� ����~��õ�� �̵��ϱ⵵ �մϴ�.
// 
// #3. "Raw Array" �� �����̳��Դϴ�.
//      �迭�� �����ͷ� 1��° ��Ҹ� ����Ű�� 
//      ������ҷ� �̵��Ҷ� ++, * �� ����մϴ�.

//      ��, next() �� ������� �ʽ��ϴ�.
//      "��� �����̳ʸ� ������ ���" ���� �Ѵٴ� ��Ģ�� ���� �ʽ��ϴ�