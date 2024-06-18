// 방법 #3. Policy Base Design 사용
// => 변하는 것(메모리 할당 정책)을 다른 클래스로 설계 하지만
// => 인터페이스로 교체 하지 말고, template 인자로 교체!


template<typename T,		// 저장할 타입
		 typename Alloc>	// 메모리 할당기
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
// 메모리 할당기 
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
