#include <iostream>
#include <coroutine>
// Step1. 함수를 coroutine으로 하려면
// => 함수 안에서 아래 3개중의 한가지 키워드를 사용하면됩니다.
// 1. co_await
// 2. co_yield
// 3. co_return

// 아래 코드는 아직 error!!
void foo()
{
	std::cout << "foo 1" << std::endl;
	
	co_await std::suspend_always{};

	std::cout << "foo 2" << std::endl;
}

int main()
{
	foo();
}
