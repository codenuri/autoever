#define USING_GUI
#include "cppmaster.h"

#include "ICalc.h"


int main()
{
	ICalc* calc = load_proxy(); // 이순간
								// 1. DLL 안의 CreateProxy 를 호출하고
								// 2. new Calc 로 Proxy 객체 생성됩니다.
								// 그렇다면, calc 는 사용후 delete 해야되지 않을까요 ?


	delete calc; // 이렇게 해도 될까요 ??
				// DLL 이 new 를 했는데, exe 가 delete 하는 것은 좋지 않습니다.
				// 자원을 할당한 동일 모듈이 자원도 반납하는 것이 안전합니다
			

}





