#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;


//bool use_flag = false; // 멀티스레드에 안전하지 않음.
std::atomic<bool> use_flag = false;

void work()
{
	// while(use_flag);
	// use_flag = true; // 이 2줄은 한번에 수행하는 것이 아래 함수.
	while (use_flag.compare_exchange_strong(use_flag, true));

	std::cout << "start. using shared resource" << std::endl;
	std::cout << "end.   using shared resource" << std::endl;

	use_flag = false;
}



int main()
{
	std::thread t1(work), t2(work);

	t1.join();
	t2.join();
}