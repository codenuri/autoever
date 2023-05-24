#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// 1. 일반 함수는 보통 리턴 값으로 결과를 반환합니다
// => 하지만 아래 함수를 스레드로 수행하면 
//    return 값이 주 스레드에 전달되는 것은 아닙니다.
int add1(int a, int b)
{
	int s = a + b;
	return s;
}

// 방법 1. 스레드로 수행한 결과를 얻을때는 out parameter 를 사용
void add2(int a, int b, int& s)
{
	s = a + b;
}


int main()
{
	int s = 0;
	std::thread t(add2, 10, 20, std::ref(s));

	t.join();

	std::cout << s << std::endl;
}



