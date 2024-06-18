// ��� #2. stratey ���� ���
// => ���ϴ� ���� �ٸ� Ŭ������!!
// => �޸��Ҵ�/���� ��å�� �ٸ� Ŭ������ 

template<typename T>
struct IAllocator
{
	virtual T*   allocate(int sz) = 0;
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

	vector(int sz)
	{
		buff = new T[sz]; 
	}
	~vector()
	{
		delete[] buff;
	}
};
int main()
{
	vector<int> v(10); 
}
