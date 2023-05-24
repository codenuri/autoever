#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// promise / future 모델 사용법

// 1. 스레드 함수는 인자로 promise 를 참조로 받아야 합니다.

//void add(int a, int b, std::promise<int>& p)
void add(int a, int b, std::promise<int>&& p)
{
	int s = a + b;

	// 2. 연산이 종료 되었으면 promise 를 사용해서 전달합니다.
	p.set_value(s); // 결과를 대기 중이던 주스레드가 깨어나게 됩니다.

	std::this_thread::sleep_for(3s);
}

int main()
{
	// 1. promise 객체를 생성합니다.
	std::promise<int> pr; 

	// 2. promise 안에서 미래의 결과를 담은 future 객체를
	//    꺼냅니다.
	std::future<int> ft = pr.get_future();


	// 3. 스레드 생성할때 Promise 객체를 참조 로 전달
	// 주스레드는 future 객체를 꺼내고 나면 더이상 promise가 필요없습니다.
	// 그래서 스레드에 전달할때
	// 1. std::ref()로 전달해도 되고
	// 2. std::move()로 전달해도 됩니다.
//	std::thread t(add, 10, 20, std::ref(pr));
	std::thread t(add, 10, 20, std::move(pr));


	// 주스레드는 다른 작업을 하다가...

	// 4. 스레드 결과가 필요할때 future 객체를 사용해서 대기합니다.
	int ret = ft.get(); // 1. 결과가 있으면 즉시 꺼내고
						// 2. 없으면 대기

	std::cout << ret << std::endl;

	t.join();
	
}



