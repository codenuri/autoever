#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

std::mutex m;

// 여러개의 스레드가 work 수행
// => 공유자원을 사용하는 시간이 아주 짦은 경우를 생각해 봅시다.
void work()
{
	m.lock();	// 1. 늦게 도착한 스레드가 뮤텍스를 획득 못했습니다.
				// 2. 늦게 도착한 스레드는 실행을 멈추고, 
				//    대기중인 스레드 목록으로 이동
				//    (OS가 linked list등의옮기는것)
				// 3. 그런데, 공유자원 사용시간이 짦다면 먼저 수행중인 스레드는
				//    이미 unlock 했을수도 있습니다.

				// 4. 이경우는 대기중으로 바꾸지 말고
				//    lock 을 획득할때까지 무한루프를수행하는 것인 효율적
	std::cout << "start. using shared resource" << std::endl;
	std::cout << "end.   using shared resource" << std::endl;
	m.unlock();
}

// 아래 코드가 자원을 사용할수 있을때 까지 무한히 루프를 수행하면서 대기
// => "spin lock", "busy wait" 라고 합니다.

// 그런데.. 이경우 

bool use_flag = false;

void work()
{
	while (use_flag);
	use_flag = true;

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