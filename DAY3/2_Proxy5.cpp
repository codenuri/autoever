#define USING_GUI
#include "cppmaster.h"

// Client 개발자는 서버 개발자에서 2개의 파일을 받으면 됩니다.

// ICalc.h       : 인터페이스가 있는 헤더
// CalcProxy.dll : Proxy 가 있는 동적 모듈

#include "ICalc.h"

ICalc* load_proxy()
{
	// #1. DLL 을 Load 합니다.
	void* addr = ec_load_module("CalcProxy.dll");

	// #2. DLL 에서 약속된 함수를 찾습니다
	using PF = ICalc* (*)();

	PF f = (PF)ec_get_function_address(addr, "CreateProxy");

	// #3. 약속된 함수를 호출해서 Proxy 를 생성합니다.
	ICalc* calc = f();
	return calc;
}

int main()
{
	ICalc* calc = load_proxy() ;   

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;
}





