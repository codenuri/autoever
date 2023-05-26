//00_false_sharing1
#include <iostream>
#include <thread>
#include "chronometry.h"

constexpr int sz = 10000000; // 0 7개. 



// 핵심 : n1, n2 가 연속적으로 선언되었습니다.
long long n1 = 0;
long long n2 = 0;



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
