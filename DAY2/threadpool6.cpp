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


// 이번 단계의 핵심 
// => add_task()가 반환값도 반환(future)

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
		// 작업함수(func) 의 반환 타입 구하기
		using RT = decltype(func(args...));

		// "함수 + 인자" 를 묶어서 packaged_task 만들기
		auto p = std::make_shared<std::packaged_task< RT()>>
							(std::bind(func, args...));

		// func 를 아직 호출하지 않았지만 반환 값을 가진 future얻기
		std::future<RT> ret = p->get_future();
		{
			std::lock_guard<std::mutex> g(m);

			// 실제 q에 보관되는 것은 packaged_task 객체를 실행하는
			// 람다 표현식 => function 에 보관가능하므로
			task_q.push([p]() { (*p)();  });
		}
		cv.notify_one();

		return ret;
	}
};

int main()
{
	ThreadPool tp(4);

	// foo 를 int 반환으로 변경하세요
	std::future<int> r1 = tp.add_task(goo, 1, 3);
	std::future<int> r2 = tp.add_task(goo, 10, 20);

	int ret1 = r1.get();
	int ret2 = r2.get();

	std::cout << ret1 << std::endl;
	std::cout << ret2 << std::endl;


	getchar();
}
