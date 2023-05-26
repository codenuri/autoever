#include <iostream>

// SIMD : 
int main()
{
	int arr1[4] = { 1,2,3,4 };
	int arr2[4] = { 5,6,7,8 };
	int arr3[4] = { 0 };

	// 4개 짜리 배열의 각 요소를 더하려면
	// "4개의 명령과 4개의 데이타 사용"

	// MIMD : 여러개의 명령으로 여러개의 데이타 처리
	for (int i = 0; i < 4; i++)
	{
		arr3[i] = arr1[i] + arr2[i];
		// arr3[0] = arr1[0] + arr2[0];
		// arr3[0] = arr1[0] + arr2[0];
	}

	for (auto e : arr3)
		std::cout << e << std::endl;
}