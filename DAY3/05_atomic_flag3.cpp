#include <iostream>
#include <atomic>
#include <thread>

// 앞의 기술(2-1)을 사용해서 클래스 만들기.
class spinlock
{
	std::atomic_flag flag; // = ATOMIC_FLAG_INIT;
public:
	void lock() { while (flag.test_and_set()); }
	void unlock() { flag.clear(); }
};

// 위 클래스 사용법
spinlock spin;

void work()
{
	spin.lock();

	std::cout << "start. using shared resource" << std::endl;
	std::cout << "end.   using shared resource" << std::endl;
	
	spin.unlock();
}

int main()
{
	std::thread t1(work),t2(work);

	t1.join();
	t2.join();
}
