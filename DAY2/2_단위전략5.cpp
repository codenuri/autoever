#include <iostream>
#include <vector>

// ����� ���� allocator �����!!
// => �ݵ�� template ���� �� �ʿ�� ������ �پ��� Ÿ�Կ� ���ؼ�
//    �޸� �Ҵ��ؾ� �ϹǷ� ��κ� template.
// => �ʿ��� ����Լ��� �̸��� ����ȭ(ǥ�ع���)�� ��ӵǾ� �ִ�.

template<typename T> class debug_alloc
{
public:

};


int main()
{
	std::vector<int, debug_alloc<int> > v;

	std::cout << "-----------------" << std::endl;

	v.resize(5);

	std::cout << "-----------------" << std::endl;
}
