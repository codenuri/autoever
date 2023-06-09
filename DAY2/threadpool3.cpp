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
class ThreadPool
{
	std::vector<std::thread> v;

	using TASK = void(*)();

	std::queue<TASK> task_q;
	std::mutex m;
	std::condition_variable cv;

	bool stop_pool = false;
public:
	ThreadPool(int cnt)
	{
		// �ٽ� 1. pool_thread_main�� ��� �Լ� �Դϴ�.
		for (int i = 0; i < cnt; ++i)
			v.emplace_back(&ThreadPool::pool_thread_main, this);
	}

	void pool_thread_main()
	{
		TASK task;

		while (true)
		{
			{
				std::unique_lock<std::mutex> ul;

				// �ٽ� 2. ����ǥ���Ŀ��� ��� ����Ÿ ����. thisĸ��
				cv.wait(ul, [this]() { return !task_q.empty(); });

				task = task_q.front();
				task_q.pop();
			}
			task();
		}
	}
	void add_task(TASK task)
	{
		{
			std::lock_guard<std::mutex> g(m);
			task_q.push(task);
		}
		cv.notify_one();
	}
};


int main()
{
	ThreadPool tp(4);

	tp.add_task(foo);
	tp.add_task(foo);
	tp.add_task(foo);
	tp.add_task(foo);
	tp.add_task(foo);
	tp.add_task(foo);

	getchar();
}
