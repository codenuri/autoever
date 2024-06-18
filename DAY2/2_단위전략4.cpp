// ��� #3. Policy Base Design ���
// => ���ϴ� ��(�޸� �Ҵ� ��å)�� �ٸ� Ŭ������ ���� ������
// => �������̽��� ��ü ���� ����, template ���ڷ� ��ü!


template<typename T,		// ������ Ÿ��
		 typename Alloc>	// �޸� �Ҵ��
class vector
{
	T* buff;

public:

	vector(int sz, IAllocator<T>* v) : ax(v)
	{
		buff = ax->allocate(sz);
	}
	~vector()
	{
		ax->deallocate(buff, size);
	}
};
//-------------------------------------------
// �޸� �Ҵ�� 
template<typename T> class MallocAllocator : public IAllocator<T>
{
public:
	T* allocate(int sz) override
	{
		void* p = malloc(sizeof(T) * sz);
		return static_cast<T*>(p);
	}
	void deallocate(T* p, int sz) override
	{
		free(p);
	}
};
int main()
{
	vector< int, MallocAllocator<int> > v(10);
}
