#include <iostream>
#include <coroutine>

// Step 8. Generator - () 연산자에서 반환값 리턴

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



/*
Generator foo()
{
	std::cout << "foo 1" << std::endl;
	co_yield 10; 
	std::cout << "foo 2" << std::endl;
}
*/
// 0~ 10 의 정수를 차례로 반환하는 코루틴
Generator foo()
{
	for (int i = 0; i < 10; i++)
		co_yield i;
}
int main()
{
	Generator g = foo();

	for (int i = 0; i < 10; i++)
	{
		std::cout << "main" << std::endl;
		std::cout << g() << std::endl;
	}
	
}
