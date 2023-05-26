#include <iostream>
#include <coroutine>

// Step 6. () 연산자, 코루틴 삭제

class Generator
{
public:
	class promise
	{
	public:
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
	void operator()() const { coro.resume(); }
};




Generator foo()
{
	std::cout << "foo 1" << std::endl;

	co_await std::suspend_always{};

	std::cout << "foo 2" << std::endl;
}

int main()
{
	Generator g = foo();

	std::cout << "main 1" << std::endl;
	g();

	std::cout << "main 2" << std::endl;
	g();

	std::cout << "main 3" << std::endl;
}
