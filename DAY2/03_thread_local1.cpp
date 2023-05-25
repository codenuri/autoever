#include <iostream>
#include <thread>
#include <string>

// 3의 배수를 순차적으로 반환하는 함수
// => 3, 6, 9, 12, ...
// => 아래 코드는 멀티스레드가 아닌 환경에서는 안전 합니다.
// => 그런데? 멀티 스레드라면 ??
int next3times()
{
//	int n = 0;		 // 지역변수, 스택에 놓인다. 함수 호출종료시 파괴
	static int n = 0;// data 메모리에 놓인다. 함수 호출종료시 파괴안됨
	n = n + 3;
	return n;
}
void foo(const std::string& name)
{
	std::cout << name << " : " << next3times() << std::endl;
	std::cout << name << " : " << next3times() << std::endl;
	std::cout << name << " : " << next3times() << std::endl;
}

int main()
{
	foo("A");
}



