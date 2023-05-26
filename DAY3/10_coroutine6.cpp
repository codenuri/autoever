#include <iostream>
#include <coroutine>

// Step 5. Generator 는 coroutine 핸들을 보관해야 합니다

class Generator
{
public:


	class promise
	{
	public:
		std::suspend_always initial_suspend() {	return {}; }
		std::suspend_always final_suspend() noexcept { return {}; }
		
		Generator get_return_object() 
		{ 
			// Generator 를 만들고, 코루틴 핸들을 초기화 한후 반환
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

	g.coro.resume();

	std::cout << "main 2" << std::endl;
	g.coro.resume();

	std::cout << "main 3" << std::endl;
}
