#include <iostream>
#include <vector>
#include <list>

int main()
{
	// 1. list �� vector �� �޸� ������ �ٸ��ϴ�.
	std::list<int>   s = { 1,2,3,4,5 };
	std::vector<int> v = { 1,2,3,4,5 };

	// 2. s, v �� ��� ��Ҹ� "������ ���" ���� �����Ҽ� ������� ?

	// �ݺ���(iterator) ����
	// => ���հ�ü�� ���� ������ �ܺο� �������� �ʰ�(���α����� ����)
	//    ������ ������� ��� ��ҿ� ���������� �����ϰ� �Ѵ�.!!

	// �̹� C++ STL ���� �ݺ��� ������ ����Ǿ� �ֽ��ϴ�.
	// => java, C#, python �� ���� ��� �� ����.
	auto p1 = s.begin();
	auto p2 = v.begin();

	// 3. p1 �� p2 �� ������ �����մϴ�.
	++p1;
	++p2;

	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
}