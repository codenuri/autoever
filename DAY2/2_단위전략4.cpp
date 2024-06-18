// 방법 #3. Policy Base Design 사용
// => 변하는 것(메모리 할당 정책)을 다른 클래스로 설계 하지만
// => 인터페이스로 교체 하지 말고, template 인자로 교체!

#include <memory>
// std::allocator<T> :  C++ 표준 allocator..  내부적으로 new, delete 사용

template<typename T,							// 저장할 타입
		 typename Alloc = std::allocator<T> >	// 메모리 할당기
class vector
{
	T* buff;

	Alloc ax;	// 메모리 할당기 객체 ax
				// 이제 vector 의 모든 멤버 함수는 메모리 할당/해지 가 필요하면
				// ax의 약속된 멤버함수를 사용해야 합니다.
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
// 메모리 할당기 
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
