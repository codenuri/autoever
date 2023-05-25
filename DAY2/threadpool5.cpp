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
	// 1. 함수를 직접 호출하면 즉시 반환값을 받을수 있습니다.
	int ret = add(1, 2);

	// 2. 함수를 packaged_task 로 묶으면 호출하지 않아도
	//    결과를 받을수 있습니다.
	std::packaged_task<int(int, int)> task(add);

	std::future<int> ft = task.get_future(); //호출하기 전에 결과받기

	task(1, 2);

	// 3. 2번처럼하면 task 사용시 인자가 필요 합니다.
	// => 아래 처럼하면 task()로 호출가능
	std::packaged_task<int()> task2(std::bind(add, 1, 2) );

	task2(); // 인자 없이 사용
			 // 하지만 결국 add(1,2)

}

