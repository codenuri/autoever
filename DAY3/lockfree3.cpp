#include <iostream>

// lockfree 자료구조는 mutex 등을 사용하는 것 보다 빠를수 있지만
// 버그의 위험이 있습니다.
// 1. lockfree 는 항상 추가/제거를 위해 메모리 주소를 비교하게 됩니다.
// 
// 2. 그런데, C/C++은 메모리 삭제후, 다시 할당하면 동일 주소가
//    나오는 경우가 많습니다.
int main()
{
	int* p1 = new int;
	printf("%p\n", p1);
	delete p1;

	int* p2 = new int;
	printf("%p\n", p2);
	delete p2;

	int* p3 = new int;
	printf("%p\n", p3);
	delete p3;
}