#include <iostream>

void foo(int& arg) { arg = 10; }

// 전달 받은 인자를 foo로 보내는 함수
template<typename T>
void send_foo(T a)
{
	foo(a);
}

int main()
{
	int n = 0;

	foo(n);
	send_foo(n);
	
	std::cout << n << std::endl;
}