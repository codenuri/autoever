// 방법 #2. stratey 패턴 사용
// => 변하는 것을 다른 클래스로!!
// => 메모리할당/해지 정책을 다른 클래스로 

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
	// 이 부분이 "strategy 패턴의 전형적인 형태"
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
