#include <iostream>
#include <mutex>
#include <latch>
#include <thread>

std::latch sync_point{ 3 }; // 1회만 가능..

void foo(std::string name)
{
	std::cout << "start  work : " << name << std::endl;
	std::cout << "finish work : " << name << std::endl;

//	sync_point.count_down();
	sync_point.arrive_and_wait(); // --count 하고
								  // count 가 0일때 까지 대기

	std::cout << "have dinner : " << name << std::endl;
}

int main()
{
	std::jthread t1(foo, "kim"), t2(foo, "lee"), t3(foo, "park");

}
