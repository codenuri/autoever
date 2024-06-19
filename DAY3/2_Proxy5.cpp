#define USING_GUI
#include "cppmaster.h"

// Client �����ڴ� ���� �����ڿ��� 2���� ������ ������ �˴ϴ�.

// ICalc.h       : �������̽��� �ִ� ���
// CalcProxy.dll : Proxy �� �ִ� ���� ���


#include "ICalc.h"

/*
ICalc* load_proxy()
{
	// #1. DLL �� Load �մϴ�.
	void* addr = ec_load_module("CalcProxy.dll");
				// linux : dlopen()    windows : LoadLibrary()


	// #2. DLL ���� ��ӵ� �Լ��� ã���ϴ�
	using PF = ICalc* (*)();

	PF f = (PF)ec_get_function_address(addr, "CreateProxy");
				// linux : dlsym()		windows : GetProcAddress()


	// #3. ��ӵ� �Լ��� ȣ���ؼ� Proxy �� �����մϴ�.
	ICalc* calc = f();
	return calc;
}
*/
// ���ο� Proxy dll �� ����� �Ǵ��� "CalcProxy.dll" �̶�� �̸��� �ؾ� �մϴ�.
// �׷���, �� �ڵ尡 ������ �ʿ� �����ϴ�.
// �׸���, �� �ڵ带 Client �����ڰ� ���� �ʿ䵵 �����ϴ�.
// ���� �����ڰ� ����� �ָ� �˴ϴ�.



int main()
{
	ICalc* calc = load_proxy() ;   

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;
}





