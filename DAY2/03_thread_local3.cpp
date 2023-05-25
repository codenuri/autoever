// 03_thread_local3

#include <iostream>
#include <thread>
#include <string>

//int* pdata = nullptr;	// 모든 스레드가 공유 합니다.
						// 스레드별 할당된 메모리는 여기 보관되면 안됩니다.

thread_local int* pdata = nullptr; // 이렇게 하면
						// 스레드별로 놓이게 되므로
						// 스레드별 할당한 메모리를 관리할수 있게 됩니다.

void init_thread()
{
	pdata = new int[1000];
}
void clean() { delete[] pdata; }

void thread_main()
{
	init_thread();

	// pdata 사용

	clean();
}

int main()
{
	std::thread t1(thread_main);
	std::thread t2(thread_main);

	t1.join();
	t2.join();
}