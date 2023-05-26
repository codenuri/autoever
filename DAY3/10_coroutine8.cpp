#include <iostream>
#include <coroutine>

// Step 7. co_await 와 co_yield

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
	void operator()() const { coro.resume(); }
};




Generator foo()
{
	std::cout << "foo 1" << std::endl;


//	co_await std::suspend_always{}; // 멈추고 호출자에게로
//	co_await std::suspend_never{}; // 멈추지 말고 계속 실행

	co_yield 10; // co_await promise객체.yield_value(10);

				// 1. promise 안에 yield_value 가 있어야 한다.
				// 
				// 2. yield_value 는 인자 값을 보관하고
				//    suspend_always 또는 suspend_never 반환


	std::cout << "foo 2" << std::endl;
}



int main()
{
	Generator g = foo();

	std::cout << "main 1" << std::endl;
	g();
	std::cout << g.coro.promise().get_value() << std::endl;

	std::cout << "main 2" << std::endl;
	g();
	std::cout << g.coro.promise().get_value() << std::endl;

	std::cout << "main 3" << std::endl;
}
