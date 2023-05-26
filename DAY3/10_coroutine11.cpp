#include <iostream>
#include <coroutine>
#include <thread>

// Step 9. std::suspend_always

class Generator
{
public:
	class promise
	{
		int value;
	public:
		int get_value() const { return value; }

		std::suspend_always yield_value(int n)
		{
			value = n;
			return  {}; // suspend_always 타입의 객체 반환
		}

		std::suspend_always initial_suspend() { return {}; }
		std::suspend_always final_suspend() noexcept { return {}; }

		Generator get_return_object()
		{
			Generator g;
			g.coro = std::coroutine_handle<promise_type>::
				from_promise(*this);

			return g;
		};

		void unhandled_exception() {}
		void return_void() {}
	};
	using promise_type = promise;

	std::coroutine_handle<promise_type> coro;

	~Generator()
	{
		if (coro) coro.destroy(); // 코루틴 프레임 워크 파괴
	}

	int  operator()() const
	{
		coro.resume(); // 코루틴 재개하고

		int ret = coro.promise().get_value();

		return ret; // co_yield 반환값 반환
	}
};

struct resume_new_thread
{
	bool await_ready() const noexcept
	{
//		std::cout << __func__ << std::endl;
		return false;     
	}
	void await_suspend(std::coroutine_handle<> coro) const noexcept
	{
//		std::cout << __func__ << std::endl;

		// 호출자에 돌아가기 전에
		// 1. 스레드를 만들어서 
		// 2. 남아 있는 코루틴 실행
		std::thread t( [coro]() { coro.resume(); } );
		t.detach();
	}

	void await_resume() const noexcept {}
};

Generator foo()
{
	std::cout << "foo 1 : " << std::this_thread::get_id() << std::endl;

	co_await resume_new_thread{};

	std::cout << "foo 2 : " << std::this_thread::get_id() << std::endl;
}

int main()
{
	Generator g = foo();

	g();

	getchar();
}


