#define USING_GUI
#include "cppmaster.h"

#include "ICalc.h"


int main()
{
	ICalc* calc = load_proxy(); // �̼���
								// 1. DLL ���� CreateProxy �� ȣ���ϰ�
								// 2. new Calc �� Proxy ��ü �����˴ϴ�.
								// �׷��ٸ�, calc �� ����� delete �ؾߵ��� ������� ?


	delete calc; // �̷��� �ص� �ɱ�� ??
				// DLL �� new �� �ߴµ�, exe �� delete �ϴ� ���� ���� �ʽ��ϴ�.
				// �ڿ��� �Ҵ��� ���� ����� �ڿ��� �ݳ��ϴ� ���� �����մϴ�
			

}





