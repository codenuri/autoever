#include <iostream>
#include <coroutine>

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
		std::cout << __func__ << std::endl;
		//return true;    // 중단하지 말고 계속 실행
		return false;     // 중단하고 호출자에게로 이동
							// 단, 그전에 아래 함수 호출하고 돌아감.
	}
	void await_suspend(std::coroutine_handle<>) const noexcept 
	{
		std::cout << __func__ << std::endl;
	}

	void await_resume() const noexcept {}
};

Generator foo()
{
	std::cout << "foo 1" << std::endl;
	
	co_await resume_new_thread{};

//	co_await std::suspend_never{};

	std::cout << "foo 2" << std::endl;
}

int main()
{
	Generator g = foo();

	g();


}


/*
struct suspend_never 
{
	constexpr bool await_ready() const noexcept {return true; }
	constexpr void await_suspend(coroutine_handle<>) const noexcept {}
	constexpr void await_resume() const noexcept {}
};

struct suspend_always 
{
	constexpr bool await_ready() const noexcept {return false;}
	constexpr void await_suspend(coroutine_handle<>) const noexcept {}
	constexpr void await_resume() const noexcept {}
};
*/