#define USING_GUI
#include "cppmaster.h"

// Proxy1.cpp 처럼 만들면
// 
// 1. 모든 클라이언트 제작자가 IPC 기술을 알아야 한다.
// 2. 서버접속에 대한 장애처리를 모든 클라이언트가 각각 해야 한다.


// Proxy        : 대행자를 만드는 패턴
// remote-proxy : 원격지 서버에 대한 대행자

class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// 위와 같은 서버의 대행자(Proxy)가 있으면
// 1. Client 제작자는 IPC 기술을 몰라도 됩니다.
// 2. "1, 2" 와 같은 명령 코드 대신 "Add, Sub" 함수를 사용하면 됩니다.
// 3. 장애 처리는 Proxy 가 담당하면 됩니다.
// 
// 4. 자주 사용되는 요청은 "캐쉬" 기능을 제공해도 됩니다.

// Proxy를 통해서 다양한 기능을 제공할수 있습니다

int main()
{
	Calc* calc = new Calc;

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;
}





