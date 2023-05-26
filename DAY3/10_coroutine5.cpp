#include <iostream>
#include <coroutine>

// Step 4. C++ Coroutine 의 원리

// promise_type 의 역활 
// => 코루틴의 시작 부터 종료 까지의 일생에서 각각의 이벤트에 대해
//    약속된 함수 호출...
//    해당 함수에서 다양한 기능을 추가할수 있습니다.

class Generator
{
public:
	class promise	
	{				
	public:
		std::suspend_always initial_suspend() 
		{ 
			std::cout << __func__ << std::endl;
			return {}; 
		}
		std::suspend_always final_suspend() noexcept { return {}; }
		Generator get_return_object() { return Generator(); };
		void unhandled_exception() {}
		void return_void() {}
	};
	using promise_type = promise;
};

Generator foo()
{
	//-------------------------------------------------
	// 컴파일러가 추가한 코드가 하는일
	// 1. sizeof(모든지역변수) + sizeof(promise_type) + 기타정보"를
	//    담은 메모리를 힙에 할당 

	// 2. promise_type 안에 있는 get_return_object() 를 호출해서
	//    Generator 객체 생성

	// 3. promise_type 안에 약속된 initial_suspend() 호출
	//   => 만든 경우만 호출됨.

	// 4. 2에서 만든 Generator 객체를 반환해서 main 으로 복귀
	//--------------------------------------------------

	std::cout << "foo 1" << std::endl;

	co_await std::suspend_always{};

	std::cout << "foo 2" << std::endl;
}

int main()
{
	foo();
}
