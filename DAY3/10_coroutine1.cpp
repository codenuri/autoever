// C++20 coroutine 이야기. 
#include <iostream>

// 서브루틴(subroutine) : 함수가 종료된 후에 호출자로 반환
// 코루틴(coroutine) : 함수중간에서 호출자로 복귀
//					  다음호출시, 이전에 중단된 지점부터 다시 실행

// C#, Python 등의 coroutine 은 아주 쉽습니다.
// C++ 은 아주 복잡하고 어렵게 되어 있습니다.

void foo()
{
	std::cout << "foo 1" << std::endl;
	std::cout << "foo 2" << std::endl;
}

int main()
{
	foo();
}
