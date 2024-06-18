#include <iostream>
#include <vector>

// 사용자 정의 allocator 만들기!!
// => 반드시 template 으로 할 필요는 없지만 다양한 타입에 대해서
//    메모리 할당해야 하므로 대부분 template.
// => 필요한 멤버함수의 이름이 문서화(표준문서)로 약속되어 있다.

template<typename T> class debug_alloc
{
public:

};


int main()
{
	std::vector<int, debug_alloc<int> > v;

	std::cout << "-----------------" << std::endl;

	v.resize(5);

	std::cout << "-----------------" << std::endl;
}
