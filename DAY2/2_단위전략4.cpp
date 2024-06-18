// ��� #3. Policy Base Design ���
// => ���ϴ� ��(�޸� �Ҵ� ��å)�� �ٸ� Ŭ������ ���� ������
// => �������̽��� ��ü ���� ����, template ���ڷ� ��ü!


template<typename T>
struct IAllocator
{
	virtual T* allocate(int sz) = 0;
	virtual void deallocate(T* p, int sz) = 0;
	virtual ~IAllocator() {}
};
template<typename T>
class vector
{
	T* buff;

	//-----------------------------------------------
	// �� �κ��� "strategy ������ �������� ����"
	IAllocator<T>* ax = nullptr;
public:
	void set_allocator(IAllocator<T>* p) { ax = p; }
	//-------------------------------------------------

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
	MallocAllocator<int> m;
	vector<int> v(10, &m);
}
