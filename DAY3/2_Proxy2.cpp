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
	Calc() { }

	int Add(int a, int b) { return ? ; }
	int Sub(int a, int b) { return ? ; }
};








int main()
{
	int server = ec_find_server("Calc");

	std::cout << "서버 번호 : " << server << std::endl;


	
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





