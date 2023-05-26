#include <iostream>
#include <thread>
#include <atomic>

// 멀티스레드를 고려하지 않고 만들어진 구조체 입니다.
struct Machine
{
	int data{ 0 };
	int count{ 0 }; // std::atomic<int> 아닙니다.
};
Machine m;

void foo()
{
//	int& cnt = m.count;

//	std::atomic<int&> cnt2 = m.count;
			// error. atomic 에는 참조타입을 넣을수 없습니다.

	std::atomic_ref<int> cnt3( m.count);
			// => C++20 부터 지원
			// => atomic 이 아닌 변수를 atomic 하게 접근가능

	for (int i = 0; i < 1000000; i++)
	{
	//	++(m.count);	// thread-safe 하지않습니다.
	//	++cnt;			// thread-safe 하지 않습니다.
	//	++cnt2;
		++cnt3; // thread-safe
		
	}
}
int main()
{	
	std::thread t1(foo), t2(foo), t3(foo);

	t1.join();
	t2.join();
	t3.join();

	std::cout << m.count << std::endl;
}
