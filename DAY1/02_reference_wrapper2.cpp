#include <iostream>
#include <functional>

// 결국 reference_wrapper 는
// 1. 내부적으로 객체의 주소를 보관하고 있고
// 2. raw reference 로의 변환이 가능한 도구 입니다
template<typename T>
class reference_wrapper
{
	T* obj;
public:
	reference_wrapper(T& r) : obj(&r) {}

	operator T& () { return *obj; }
};
int main()
{
	int v1 = 10, v2 = 20;
	reference_wrapper<int> r1 = v1;
	reference_wrapper<int> r2 = v2;
	r1 = r2;

	int& r = r1; // raw reference 와의 호환(암시적 변환)
				 // r1.operator int&()

	std::cout << v1 << std::endl; 
	std::cout << v2 << std::endl; 
	std::cout << r1 << std::endl; 
	std::cout << r2 << std::endl; 
}