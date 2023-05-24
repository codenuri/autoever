#include <iostream>

void foo(int& arg) { arg = 10; }

// 전달 받은 인자를 foo로 보내는 함수
// => 처음 설계시 부터, call by value 방식으로 설계된 함수
//    (멀티스레드 관련 함수는 거의 대부분 call by value 방식)
// => 그런데, 이함수에게 인자를 참조로 보내고 싶다.
template<typename T>
void send_foo(T a)
{
	foo(a);
}

int main()
{
	int n = 0;

//	foo(n);
//	send_foo(n); // 받으면서 복사본 생성
//	send_foo(&n);// 복사본은 아니지만, 포인터는 => 참조 변환 안됨.

//	std::reference_wrapper<int> r(n);
//	send_foo(r); // n 을 참조로 전달하겠다는 의도.

	send_foo( std::ref(n) );
			// std::ref(n) : reference_wrapper 를 만들어주는 함수


	std::cout << n << std::endl;
}