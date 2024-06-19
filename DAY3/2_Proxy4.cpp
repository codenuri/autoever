#define USING_GUI
#include "cppmaster.h"

// Proxy 는 Update 될수 있습니다
// 약한 결합을 위해서 Proxy 인터페이스 제공

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
//	Calc* calc = new Calc; // 강한 결합

	ICalc* calc = new ? ;    // ? 를 어떻게 해야 할까요 ?
			//    new ICalc; // error	
			//    new Calc;  // ok. 하지만 강한 결합
			//				 proxy5.cpp 에서 해결


	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;
}





