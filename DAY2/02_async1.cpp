#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// async 특징
// 1. 사용자가 "std::thread" 를 사용할 필요 없이
//    std::async() 내부적으로 스레드 생성
//    정확히는 "스레드 풀" 사용

// 2. 스레드를 고려하지 않은 함수(return 을 결과를 반환하는 함수)
//    를 스레드로 수행해서 결과를 얻을수 있다.
//    std::future<> 로 결과 얻기




// 스레드를 고려하지 않은 일반 함수라면 아래 처럼 작성합니다.
int add(int a, int b)
{
	std::this_thread::sleep_for(3s);
	return a + b;
}

int main()
{
	// packaged_task : 함수를 즉시 호출한것이 아니라. 보관했다가
	//				   필요할때 호출 또는 스레드로 수행
	//                 => std::thread 를 다시 사용해서 스레드로수행
//	std::packaged_task<int(int, int)> task(add);

	// std::async : 함수를 즉시 스레드로 수행
	//				std::thread 사용할 필요 없음
	std::future<int> ft = std::async(&add, 1, 2);

	std::cout << "continue main" << std::endl;

	int ret = ft.get();

	std::cout << "result : " << ret << std::endl;
}

