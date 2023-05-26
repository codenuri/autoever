#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;


// std::atomic<bool> : 환경에 따라 lock-free 일수도 있고 
//					   아닐수도 있습니다.

// std::atomic_flag : 항상 lock-free 임을 보장 합니다.


//std::atomic<bool> use_flag = false;

//std::atomic_flag use_flag = ATOMIC_FLAG_INIT; // C++20 이전에 필요
std::atomic_flag use_flag; // C++20 부터는 초기화 필요 없음.

void work()
{
	// use_flag 가 set 되어 있으면 clear 될때까지 무한루프
	// clear 라면 set 하고 탈출
	while (use_flag.test_and_set() );

	std::cout << "start. using shared resource" << std::endl;
	std::cout << "end.   using shared resource" << std::endl;

	use_flag.clear();
}



int main()
{
	std::thread t1(work), t2(work);

	t1.join();
	t2.join();
}