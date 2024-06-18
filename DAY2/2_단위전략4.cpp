// ��� #3. Policy Base Design ���
// => ���ϴ� ��(�޸� �Ҵ� ��å)�� �ٸ� Ŭ������ ���� ������
// => �������̽��� ��ü ���� ����, template ���ڷ� ��ü!

#include <memory>
// std::allocator<T> :  C++ ǥ�� allocator..  ���������� new, delete ���

template<typename T,							// ������ Ÿ��
		 typename Alloc = std::allocator<T> >	// �޸� �Ҵ��
class vector
{
	T* buff;

	Alloc ax;	// �޸� �Ҵ�� ��ü ax
				// ���� vector �� ��� ��� �Լ��� �޸� �Ҵ�/���� �� �ʿ��ϸ�
				// ax�� ��ӵ� ����Լ��� ����ؾ� �մϴ�.
public:
	vector(int sz)
	{
		buff = ax.allocate(sz);
	}
	~vector()
	{
		ax.deallocate(buff, size);
	}
};
//-------------------------------------------
// �޸� �Ҵ�� 
template<typename T> class MallocAllocator
{
public:
	inline T* allocate(int sz)
	{
		void* p = malloc(sizeof(T) * sz);
		return static_cast<T*>(p);
	}
	inline void deallocate(T* p, int sz)
	{
		free(p);
	}
};

int main()
{
	vector< int, MallocAllocator<int> > v(10);
}
