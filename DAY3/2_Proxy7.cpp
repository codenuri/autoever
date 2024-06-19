#define USING_GUI
#include "cppmaster.h"

#include "ICalc.h"


int main()
{
	// Proxy ������� ��Ģ

	ICalc* calc1 = load_proxy(); 

	calc1->AddRef();		// ��Ģ 1. Proxy �� ó�� ������ �����������

	ICalc* calc2 = calc1;	
	calc2->AddRef();		// ��Ģ 2. Proxy �����͸� �����ϸ� ������� ����


	calc2->Release();		// ��Ģ 3. �����͸� ���̻� ������� ������ ������� ����

	std::cout << "---------------\n";
	
	calc1->Release();

	std::cout << "---------------\n";

}





