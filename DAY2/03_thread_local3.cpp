// 03_thread_local3

#include <iostream>
#include <thread>
#include <string>

int* pdata = nullptr;

void init_thread()
{
	pdata = new int[1000];
}

void thread_main()
{
	init_thread();

	// pdata »ç¿ë
}

int main()
{
	std::thread t1(thread_main);
	std::thread t2(thread_main);

	t1.join();
	t2.join();
}