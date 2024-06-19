#define USING_GUI
#include "cppmaster.h"

// Proxy �� Update �ɼ� �ֽ��ϴ�
// ���� ������ ���ؼ� Proxy �������̽� ����

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
//	Calc* calc = new Calc; // ���� ����

	ICalc* calc = new ? ;    // ? �� ��� �ؾ� �ұ�� ?
			//    new ICalc; // error	
			//    new Calc;  // ok. ������ ���� ����
			//				 proxy5.cpp ���� �ذ�


	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;
}





