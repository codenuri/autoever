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

// �� DLL �� �����(Ŭ���̾�Ʈ ������) ��

// DLL ������ Ŭ����(Proxy) �̸��� ���� ���ϰ�, ����ص� �ȵ˴ϴ�.
// ����, DLL ���ο��� ��ü�� �����ϴ� �Լ��� �����մϴ�

// Proxy �� ������Ʈ �Ǿ DLL ���ο��� �ݵ�� �Ʒ� �Լ��� �־�� �մϴ�.
extern "C" __declspec(dllexport)	// windows DLL ���� �Լ� �����Ҷ� �ʿ�
ICalc* CreateProxy()
{
	return new Calc;
}

// ���� �ϴ� ��
// (������ ���� ��ư => visual studio 2022 ���� ����
//  => ������ ��� ������Ʈ����(developmemet command prompt)
// 
// cl CalcProxy.cpp /LD  /link user32.lib   gdi32.lib   kernel32.lib

// => CalcProxy.dll �����˴ϴ�.

// /LD �ɼ� : DLL �� �����ش޶�� ��

