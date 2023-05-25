#include <iostream>
#include <thread>
#include <string>

int next3times()
{
	//	int n = 0;		// 지역변수, 스택 사용, 스레드당 별도의 공간 사용
	// static int n = 0;	// data 메모리, 모든 스레드가 공유		
	thread_local static int n = 0;
			// => 스레드당 한개의 data 메모리
			// => 함수호출이 종료 되어도 파괴되지 않습니다.
			// => Thread local Storage(TLS) 또는
			//    Thread Specific Storage(TSS) 라고 합니다.
	n = n + 3;
	return n;
}
// 전역변수도 TSS 에 만들수 있습니다.
int g1 = 0; // 모든 스레드가 공유
thread_local int g2 = 0; // 스레드 별로 따로 사용하는 전역변수


void foo(const std::string& name)
{
	std::cout << name << " : " << next3times() << std::endl;
	std::cout << name << " : " << next3times() << std::endl;
	std::cout << name << " : " << next3times() << std::endl;
}
int main()
{
	std::thread t1(foo, "A");
	std::thread t2(foo, "\tB");

	t1.join();
	t2.join();
}
// 결과 예측해 보세요..

// 주의
// => 대부분 OS에서 TLS(TSS) 의 크기제한이 있습니다
// => windows : sizeof(int) * 1088 크기입니다.
// => 많은 공간이 필요 하면
//    스레드 별로 힙에 할당하고 주소만 TLS 에 보관하세요.


