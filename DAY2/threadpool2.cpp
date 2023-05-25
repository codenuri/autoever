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

//-----------------------------------------------------
std::vector<std::thread> v;

using TASK = void(*)();

std::queue<TASK> task_q;

std::mutex m;
std::condition_variable cv;

bool stop_pool = false;

//-------------------------
void pool_thread_main()
{
	TASK task;

	while (true)
	{
		{
			std::unique_lock<std::mutex> ul;

			cv.wait(ul, []() { return !task_q.empty(); });

			task = task_q.front();
			task_q.pop();
		}
		task(); // 작업 실행!
	}
}

void add_task(TASK task)
{
	{
		std::lock_guard<std::mutex> g(m);

		task_q.push(task);
	}
	cv.notify_one(); // 대기중인 스레드 깨우기.
}


void init_pool(int cnt)
{
	for (int i = 0; i < cnt; ++i)
		v.emplace_back(pool_thread_main);
			// v.push_back( std::thread(pool_thread_main))의 의미
}

int main()
{
	init_pool(4); // 초기에 4개의 스레드 생성

	add_task(foo);
	add_task(foo);
	add_task(foo);
	add_task(foo);
	add_task(foo);
	add_task(foo);

	getchar();
}
