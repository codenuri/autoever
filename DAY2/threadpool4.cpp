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
using namespace std::literals;


// 이번 단계의 핵심 
// => 작업함수가 인자를 가질수 있도록..

void goo(int a, double d) { }

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

	// std::function : 함수주소와 함수 인자를 같이 보관 가능
	//					=> std::bind() 와 같이 사용하면!!
//	using TASK = void(*)();
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
	// 함수 와 인자를 모두 받아야 합니다.(가변인자 템플릿)
	template<typename F, typename ... ARGS>
	void add_task(F&& func, ARGS&& ... args)
	{
		// "함수주소(func) + 인자(args...) 를 묶어서" 
		// => 인자 없는 함수 f 로 만들기
		std::function<void()> f = std::bind(func, args...);
		// f(); // func(args...)
		{
			std::lock_guard<std::mutex> g(m);
			task_q.push(f);
		}
		cv.notify_one();
	}
};
int main()
{
	ThreadPool tp(4);

	tp.add_task(foo, "A");
	tp.add_task(foo, "B");
	tp.add_task(foo, "C");
	tp.add_task(foo, "D");
	tp.add_task(foo, "E");
	tp.add_task(foo, "F");
	tp.add_task(goo, 10, 3.4);

	getchar();
}
