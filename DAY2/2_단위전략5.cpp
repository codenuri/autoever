#include <iostream>
#include <vector>

// 사용자 정의 allocator 만들기!!
// => 반드시 template 으로 할 필요는 없지만 다양한 타입에 대해서
//    메모리 할당해야 하므로 대부분 template.
// => 필요한 멤버함수의 이름이 문서화(표준문서)로 약속되어 있다.

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

	// 위 2개의 핵심 함수 외에도, 아래 3개의 멤버가 필요 합니다.(관례적인 코드)
	debug_alloc() = default;
	template<typename U> debug_alloc(const debug_alloc<U>&) {} 
									// generic constructor 
	using value_type = T;
};

int main()
{
	std::vector<int, debug_alloc<int> > v;

	std::cout << "-----------------" << std::endl;

	v.resize(5);	// 새롭게 5개 버퍼 필요, debug_alloc 사용

	std::cout << "-----------------" << std::endl;

	v.resize(10); // 1. 새로운 10개 할당 - allocate 사용
				  // 2. 5개 버퍼 내용 => 10개 에 복사
				  // 3. 5개 버퍼 제거 - deallocate 사용

	std::cout << "-----------------" << std::endl;

	v.clear(); // 이 순간 vector 가 사용하던 메모리가 제거될까요 ???
			   // => 메모리 제거 안됩니다.
			   // => 단지 size 변수만 0으로 하고 메모리는 제거 안합니다.

	v.shrink_to_fit(); // 이 함수를 호출해주면 메모리가 제거 됩니다.

	std::cout << "-----------------" << std::endl;

}
