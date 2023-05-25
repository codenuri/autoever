// threadpool1
#include <iostream>
#include <string>
#include <mutex>
#include <condition_variable>
#include <future>
#include <vector>
#include <queue>
#include <chrono>
using namespace std::literals;

void foo()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::this_thread::get_id() << " : " << i
			      << std::endl;

		std::this_thread::sleep_for(400ms);
	}
}
int main()
{
	// 네트워크 서버를 생각해 봅시다.
	while (1)
	{
		getchar();

		std::thread t(foo);
		t.detach();
	}
}
