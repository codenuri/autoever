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
	// 1. packaged_task 객체를 생성합니다.
	std::packaged_task<int(int, int)> task(add);

	// 2. packaged_task 에서 future 를 꺼낼수 있습니다.
	std::future<int> ft = task.get_future();

	// 3. task 를 호출(주스레드)하거나, 스레드로 실행합니다.
	// task : () 연산자가 재정의 되어 있어서 함수처럼 사용가능
	// task(1, 2); // 주스레드가 직접 호출한것

	// std::thread t(task, 1, 2); // error.  
							// task 는 복사 금지 이므로
							// std::ref(), std::move() 사용
	
	// std::ref(task) : task 를 계속 사용하고싶을때
	// std::move(task) : task 객체가 더이상 필요 없을때
	std::thread t(std::ref(task), 1, 2);

	int ret = ft.get();

	std::cout << ret << std::endl;

	t.join();
}

