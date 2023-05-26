#include <iostream>
#include <coroutine>

// Step 3. promise_type 의 규칙
// 1. 클래스로 설계되어야 합니다

// 2. 반드시 약속된 함수를 만들어야 합니다(최소 5개 규칙 )



class Generator
{
public:
	class promise	 // 어떤 이름도 상관없습니다. Generator 안에서만
	{				 // promise_type 으로 노출하면 됩니다.
	public:
		std::suspend_always initial_suspend() { return {}; }
		std::suspend_always final_suspend() noexcept { return {}; }
		Generator get_return_object() { return Generator(); };
		void unhandled_exception() {}
		void return_void() {}
	};
	using promise_type = promise;

};

Generator foo()
{
	std::cout << "foo 1" << std::endl;

	co_await std::suspend_always{};

	std::cout << "foo 2" << std::endl;
}

int main()
{
	foo();
}
