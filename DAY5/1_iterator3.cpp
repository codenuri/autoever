#include <iostream>
#include <vector>
#include <list>

// �Ʒ� �ڵ�� "Java ���" �� �ݺ��� �ڵ� �Դϴ�.
// => ������ ������ �ʽ��ϴ�. ������ ���� �ڵ�

int main()
{
	slist<int>  s = { 1,2,3 };
	vector<int> v = { 1,2,3 };

	// ��Ģ #1. ��� �����̳�(�÷���)������ �ݺ��ڸ� ������ iterator() �Լ��� �ֽ��ϴ�.
	// => �������̽��� ��Ģ�� ����.
	auto it1 = s.iterator();
	auto it2 = v.iterator();

	// ��Ģ #2. ��� �ݺ��ڴ� ������ �����ؾ� �մϴ�
	// => hasNext(), next() ��� �Լ��� �־�� �մϴ�.
	// => ��� �ݺ��ڰ� ���Ѿ� �ϴ� ��Ģ�� "�������̽�"�� ����

	while (it1.hasNext())
	{
		std::cout << it1.next() << std::endl;
	}

	while (it2.hasNext())
	{
		std::cout << it2.next() << std::endl;
	}
}

