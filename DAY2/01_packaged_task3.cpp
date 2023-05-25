#include <iostream>
#include <thread>
#include <future>

// 스레드를 고려하지 않은 일반 함수라면 아래 처럼 작성합니다.
int add(int a, int b)
{
	return a + b;
}

int main()
{
	std::packaged_task<int(int, int)> task(add);

	// 핵심 : task 객체를 여러번 사용하는 방법
	task(1, 2); // ok. 최초 실행

//	task(1, 2); // 예외 발생.
				// 내부적으로 promise 등을 사용하기 때문에
				// 다시 호출되게 하려면 reset 해야 합니다.

	task.reset();
	task(1, 2);
}

