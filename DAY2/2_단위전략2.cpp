// vector 의 메모리 할당/해지 정책을 사용자가 변경할수 있게 만들어 봅시다.

// 방법 #1. template method 패턴 사용
// => 변하는 것을 "가상함수"로 
// => 메모리 할당/해지 방법을 "가상함수로"

template<typename T>
class vector
{
	T* buff;
	int size;
public:
	// 메모리 할당/해지 를 위한 가상함수
	virtual T* allocate(int sz)           { return new T[sz]; }
	virtual void deallocate(T* p, int sz) { delete[] p; }

	// 이제 vector 의 모든 멤버 함수에서는 메모리 할당/해지가 필요하면
	// allocate/deallocate 를 사용해야 합니다.
	vector(int sz)
	{
		buff = allocate(sz); 
	}
	~vector()
	{
		deallocate(buff, size)
	}
};

// 위 디자인의 의도는 
// 메모리 할당/해지를 방식을 변경하려면 vector 의 파생 클래스를 만들라는 것!!!

template<typename T> class myvector : public vector<T>
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
//	vector<int> v(10); // v는 내부적으로 int 10개 할당
	myvector<int> v(10); // 메모리 할당 방식이 변경(new 가 아닌 malloc)된
						 // vector 
}

// vector 예제에서, 위 방식(template method)을 적용할때의 단점 
// => myvector 가 메모리 할당 방식을 소유하게 된다.
// => list, set, map 도 메모리 할당 방식을 변경하려면
//    파생 클래스를 만들어서 동일한 코드를 작성해야 한다.

// "메모리 할당 방식을 담은 정책" 을 모든 컨테이너가 사용할수 있게 하는 것이 
// 좋지 않을까 ??