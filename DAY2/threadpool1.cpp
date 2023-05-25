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
		// 1. 클라이언트의 접속을 대기 합니다.
		getchar();

		// 2. 클라이언트가 접속하면 새로운 스레드를 만들어서
		//    요청을 처리합니다.
		std::thread t(foo);
		t.detach();

		// 3. 주스레드는 다시 1번으로 이동해서 다른 클라이언트 접속 대기
	}
}
// 단점 1. 스레드의 생성과 파괴가 계속 일어 납니다.
// => OS 입장에서 스레드 생성/파괴는 많은 시간이 소요 됩니다.
// => 일을 수행후에 파괴하지 말고, 대기하는 것이 좋습니다.

// 단점 2.  요청이 있을때 마다 스레드 생성
// => 스레드 갯수를 제한할수 없습니다.