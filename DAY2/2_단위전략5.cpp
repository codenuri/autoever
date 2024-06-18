#include <iostream>
#include <vector>

// ����� ���� allocator �����!!
// => �ݵ�� template ���� �� �ʿ�� ������ �پ��� Ÿ�Կ� ���ؼ�
//    �޸� �Ҵ��ؾ� �ϹǷ� ��κ� template.
// => �ʿ��� ����Լ��� �̸��� ����ȭ(ǥ�ع���)�� ��ӵǾ� �ִ�.

template<typename T> class debug_alloc
{
public:
	inline T* allocate(std::size_t sz)
	{
		void* p = malloc(sizeof(T) * sz);
		printf("allocate : %p, %zu cnt\n", p, sz);
		return static_cast<T*>(p);
	}

	inline void deallocate(T* p, std::size_t sz)
	{
		printf("deallocate : %p, %zu cnt\n", p, sz);
		free(p);
	}

	// �� 2���� �ٽ� �Լ� �ܿ���, �Ʒ� 3���� ����� �ʿ� �մϴ�.(�������� �ڵ�)
	debug_alloc() = default;
	template<typename U> debug_alloc(const debug_alloc<U>&) {} 
									// generic constructor 
	using value_type = T;
};

int main()
{
	std::vector<int, debug_alloc<int> > v;

	std::cout << "-----------------" << std::endl;

	v.resize(5);	// ���Ӱ� 5�� ���� �ʿ�, debug_alloc ���

	std::cout << "-----------------" << std::endl;

	v.resize(10); // 1. ���ο� 10�� �Ҵ� - allocate ���
				  // 2. 5�� ���� ���� => 10�� �� ����
				  // 3. 5�� ���� ���� - deallocate ���

	std::cout << "-----------------" << std::endl;

	v.clear(); // �� ���� vector �� ����ϴ� �޸𸮰� ���ŵɱ�� ???
			   // => �޸� ���� �ȵ˴ϴ�.
			   // => ���� size ������ 0���� �ϰ� �޸𸮴� ���� ���մϴ�.

	v.shrink_to_fit(); // �� �Լ��� ȣ�����ָ� �޸𸮰� ���� �˴ϴ�.

	std::cout << "-----------------" << std::endl;

}
