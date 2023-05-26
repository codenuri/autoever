//00_false_sharing1
#include <iostream>
#include <thread>
#include "chronometry.h"

constexpr int sz = 10000000; // 0 7개. 



// 해결책 1. 두개 변수를 캐쉬 크기만큼 띄우면 됩니다.

// 1. 패딩 사용
/*
long long n1 = 0;
char buf[64] = { 0 };
long long n2 = 0;
*/

// 2. C++11 alingas 사용
// => 변수의 시작 주소를 특정 배수로(align 설정)
// => n1, n2 변수 주소를 출력해 보세요
//    alignas 이 없으면  2개 변수가 붙어 있지만
//    alignas 가 있으면 64 배수입니다.
alignas(64) long long n1 = 0;
alignas(64) long long n2 = 0;




void f1()
{
	// 천만번 루프 n1 1증가
	for (int i = 0; i < sz; i++)
	{
		n1 += 1;
	}
}

void f2()
{
	// f1 함수와 동일, 단 n2에 결과 보관
	for (int i = 0; i < sz; i++)
	{
		n2 += 1;
	}
}

void single_thread()
{
	f1();
	f2();
}
void multi_thread()
{
	std::thread t1(f1);
	std::thread t2(f2);

	t1.join();
	t2.join();
}

int main()
{
	chronometry(single_thread);
	chronometry(multi_thread);
	chronometry(single_thread);
	chronometry(multi_thread);

}
