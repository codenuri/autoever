// CalcProxy.cpp

#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// 이 DLL 의 사용자(클라이언트 제작자) 는

// DLL 내부의 클래스(Proxy) 이름을 알지 못하고, 사용해도 안됩니다.
// 따라서, DLL 내부에서 객체를 생성하는 함수를 제공합니다

// Proxy 가 업데이트 되어도 DLL 내부에는 반드시 아래 함수가 있어야 합니다.
extern "C" __declspec(dllexport)	// windows DLL 에서 함수 노출할때 필요
ICalc* CreateProxy()
{
	return new Calc;
}

// 빌드 하는 법
// (윈도우 시작 버튼 => visual studio 2022 폴더 에서
//  => 개발자 명령 프롬프트실행(developmemet command prompt)
// 
// cl CalcProxy.cpp /LD  /link user32.lib   gdi32.lib   kernel32.lib

// => CalcProxy.dll 생성됩니다.

// /LD 옵션 : DLL 로 빌드해달라는 것

