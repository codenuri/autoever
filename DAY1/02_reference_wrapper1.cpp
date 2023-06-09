#include <iostream>
#include <functional>
// C++ 레퍼런스 : 값의 이동, 레퍼런스 자체는 이동될수 없다
// reference_wrapper : 이동가능한 참조
//					   대입연산시 참조가 이동
int main()
{
	int v1 = 10, v2 = 20;

//	int& r1 = v1;
//	int& r2 = v2;
	std::reference_wrapper<int> r1 = v1;
	std::reference_wrapper<int> r2 = v2;

	r1 = r2;

	// 결과 예측해 보세요.        // raw reference  reference_wrapper
	std::cout << v1 << std::endl; // 20				10
	std::cout << v2 << std::endl; // 20				20
	std::cout << r1 << std::endl; // 20				20
	std::cout << r2 << std::endl; // 20				20
}