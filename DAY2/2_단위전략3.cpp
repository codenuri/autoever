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
	MallocAllocator<int> m;
	vector<int> v(10, &m); 
}
// 위 방식의 특징
// 장점 : 메모리 할당 정책이 컨테이너(vector)와 분리되어 있다.
//        vector 뿐 아니라 다른 컨테이너(list, set 등)도 MallocAllocator 사용가능
// 
// 단점 : allocate/deallocate 가 "가상함수" 이다. 호출시 느리다
//        가상함수 테이블 때문에 메모리 오버헤드가 있다.
//        STL 같은 표준 라이브러리는 "절대 오버헤드"가 있으면 안된다.