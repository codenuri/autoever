#include <iostream>
#include <mutex>
#include <latch>
#include <thread>
#include <barrier>

// std::latch sync_point{ 3 }; // 1회만 가능..

// std::barrier sync_point{ 3 }; // 여러번 사용가능한 latch


// 2번째 인자로 함수 전달 가능합니다.
// => 단, 반드시 예외가 없는 함수만 가능합니다.(noexcept 필요)
void arrive_sync_point() noexcept
{
	std::cout << "모두 도착" << std::endl;
}

std::barrier sync_point(3, arrive_sync_point );


void foo(std::string name)
{
	std::cout << "start  work : " << name << std::endl;
	std::cout << "finish work : " << name << std::endl;

	sync_point.arrive_and_wait();	// 1. --count 하고
									// 2. count == 0 대기
									// 3. 0이면 count 를 다시 3으로


	std::cout << "have dinner : " << name << std::endl;

	sync_point.arrive_and_wait();

	std::cout << "go home : " << name << std::endl;
}

int main()
{
	std::jthread t1(foo, "kim"), t2(foo, "lee"), t3(foo, "park");

}

