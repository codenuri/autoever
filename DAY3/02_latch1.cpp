#include <iostream>
#include <mutex>
#include <thread>
#include <latch>
#include <chrono>
using namespace std::literals;
// C++11 : mutex, condition_variable
// C++17 : shared_mutex
// C++20 : semaphore, latch, barrier

// latch : 카운팅 기반의 간단한 동기화 도구. 
//	       없어도 condition_variable 로 구현 가능.

std::latch complete_latch(3); // 내부적으로 3을 보관

void foo(const std::string& name)
{
	std::cout << "start  work : " << name << std::endl;
	std::cout << "finish work : " << name << std::endl;

	complete_latch.count_down(); // --count

	std::this_thread::sleep_for(1s);

	std::cout << "go home     : " << name << std::endl;
}
int main()
{
	std::jthread t1(foo, "kim"), 
		         t2(foo, "lee"), 
		         t3(foo, "park");

	complete_latch.wait(); // 카운트가 0일때까지 대기

	std::cout << "receive signal" << std::endl;
}
