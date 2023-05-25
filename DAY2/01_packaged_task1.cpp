#include <iostream>
#include <thread>
#include <future>

// 스레드를 고려하지 않은 일반 함수라면 아래 처럼 작성합니다.
int add1(int a, int b)
{
	return a + b;
}

// 스레드를 고려한다면 아래(add) 처럼 작성해야 합니다
// => 그런데, 이미 작성된 위 함수를 "스레드로 수행후 결과를 얻을수 없을까요 ?"
// 1. std::packaged_task => 보관 했다가 실행
// 2. std::async()		 => 즉시 스레드로 실행.



// add 함수가 promise 를 통해서 반환값 전달
// 다른 스레드에 반환
void add(std::promise<int>&& p, int a, int b)
{
	p.set_value(a + b);
}

int main()
{
	std::promise<int> pm;
	std::future<int> ft = pm.get_future();

	std::thread t(add, std::move(pm), 10, 20);

	int ret = ft.get();

	t.join();
}



