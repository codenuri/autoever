#include <iostream>
#include <functional>
using namespace std::placeholders;

void foo(int n, int& r)
{
	r = 100;
}

int main()
{
	std::function<void(int)> f;
	
	int n = 0;
//	{
		// 이항함수 foo 의 2번째 인자를 n으로 고정한 단항함수 f 만들기
		// f = std::bind(&foo, _1, n);
		// => f는 내부적으로 "n" 을 보관할까요 ?
		//    n의 값 "0" 을 보관할까요? => 정답.
		// 
		// 0이 아닌 n 자체를 보관하게 하려면 아래 처럼 해야 합니다.
		f = std::bind(&foo, _1, std::ref(n) );
//	}
	f(0); // foo(0, n)

	std::cout << n << std::endl;
}

