#include <iostream>

int main()
{
	__declspec(align(16)) int arr1[4] = { 1,2,3,4 };
	__declspec(align(16)) int arr2[4] = { 5,6,7,8 };
	__declspec(align(16)) int arr3[4] = { 0 };

	//	int arr1[4] = { 1,2,3,4 };
	//	int arr2[4] = { 5,6,7,8 };
	//	int arr3[4] = { 0 };

	std::cout << sizeof(arr1) << std::endl;

	__asm
	{
		movdqa xmm0, arr1		// move aligned double quad word
		movdqa xmm1, arr2
		paddd xmm0, xmm1		// 한번의 명령으로 4개 데이타 덧셈	
					// SIMD : Single Instruction Multiple Data 
					// => 결국 CPU 가 제공하는 기능
					// => C++23 부터 std::vector 등의 덧셈을 SIMD 사용
		movdqa arr3, xmm0
	}

	for (auto e : arr3)
		std::cout << e << std::endl;
}