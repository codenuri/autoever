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
// => 단점 : 주스레드에서 연산이 완료된 시점을 알수 없습니다.
// => 스레드의 종료를 대기할수 있지만
// => 연산의 종료를 대기할수 없습니다.

// 해결책
// 1. promise/future 모델
// 2. packaged_task
// 3. async
// 4. 직접 동기화 객체 사용(mutex, condition_variable)
void add2(int a, int b, int& s)
{
	s = a + b;

	// 연산은 종료 되었지만.. 마무리 작업에 시간이 걸린다고 가정
	std::this_thread::sleep_for(3s);
}

int main()
{
	int s = 0;
	std::thread t(add2, 10, 20, std::ref(s));

	t.join();

	std::cout << s << std::endl;
}



