#include <memory>

int main()
{
	// C++ 표준에 이미 "std::shared_ptr" 이라는 스마트 포인터가 있는데..
	// 이걸 사용하면 안되나요 ??
	// 안됩니다. 아래 코드 생각해 보세요

	std::shared_ptr<ICalc> sp1( load_proxy() ); 
				// 1. load_proxy 는 DLL 내부에 있는 함수(CreateProxy)에서 new 를 하게 됩니다.
				// 2. 그 주소를 sp1 이 보관하다가
				// 3. sp1 이 파괴 될때 "delete" 하게 됩니다.
				//    즉, delete 를 하는 것이 "실행파일" 입니다!!

	sp<ICalc> sp2(load_proxy());
				// 1. sp2 가 파괴될때 "delete" 가 아니라 "Release()" 를 호출합니다.
				// 2. Release() 에서 "delete" 하는데
				// 3. Release() 는 DLL 안에 있는 함수 입니다.
				//    즉, delete 를 dLL 안에서 하게 됩니다.

	// 위와 같은 이유로 C++ 표준에 "std::shared_ptr" 이라는 스마트 포인터가 있지만
	// 다양한 이유로 많은 오픈소스가 자신만의 스마트 포인터를 사용하고 있습니다.
}