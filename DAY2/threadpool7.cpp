// threadpool1
#include <iostream>
#include <string>
#include <mutex>
#include <condition_variable>
#include <future>
#include <vector>
#include <queue>
#include <chrono>
#include <functional>
#include <memory>
using namespace std::literals;


int goo(int a, int b) { return a + b; }

void foo(const std::string& name)
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << name << " : " << std::this_thread::get_id() << " : " << i
			<< std::endl;

		std::this_thread::sleep_for(400ms);
	}
}
//-----------------------------------------------------
class ThreadPool
{
	std::vector<std::thread> v;

	using TASK = std::function<void()>;

	std::queue<TASK> task_q;
	std::mutex m;
	std::condition_variable cv;

	bool stop_pool = false;
public:
	ThreadPool(int cnt)
	{
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

				cv.wait(ul, [this]() { return !task_q.empty(); });

				task = task_q.front();
				task_q.pop();
			}
			task();
		}
	}


	template<typename F, typename ... ARGS>
	decltype(auto) add_task(F&& func, ARGS&& ... args)
	{
		using RT = decltype(std::forward<F>(func)(
							std::forward<ARGS>(args)...));


		auto p = std::make_shared<std::packaged_task< RT()>>
			(std::bind(std::forward<F>(func), 
				       std::forward<ARGS>(args)...));



		std::future<RT> ret = p->get_future();
		{
			std::lock_guard<std::mutex> g(m);

			task_q.push([p]() { (*p)();  });
		}
		cv.notify_one();

		return ret;
	}
};

int main()
{
	ThreadPool tp(4);
	
	std::future<int> r1 = tp.add_task(goo, 1, 3);
	std::future<int> r2 = tp.add_task(goo, 10, 20);

	int ret1 = r1.get();
	int ret2 = r2.get();

	std::cout << ret1 << std::endl;
	std::cout << ret2 << std::endl;


	getchar();
}
