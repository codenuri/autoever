#include <iostream>
#include <coroutine>

// Step2. coroutine 지켜야 하는 규칙 
// 1. "promise_type" 이라는 멤버 타입을 가진 타입을 반환해야 합니다.

// 아래 코드는 아직 error

class Generator
{
public:
	using promise_type = int;
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
