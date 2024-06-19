#define USING_GUI
#include "cppmaster.h"


class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// Proxy 제작자 : Server 개발자
// Proxy 사용자 : Client 개발자

int main()
{
	// Client 가 아래처럼 Proxy 이름을 직접 사용하면 "강한 결합" 입니다.
	// Proxy 가 Update 되면 아래 코드는 수정되어야 합니다.
	// Client 는 Proxy 사용시 "약한 결합" 으로 사용해야 합니다.
	Calc* calc = new Calc; // 나쁜 코드
							// 해결은 Proxy4.cpp

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;
}





