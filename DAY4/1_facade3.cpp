#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;


// SRP(Single Responsibility Principle)
// => 단일 책임의 원칙
// => 하나의 클래스는 하나의 책임만..



class NetworkInit
{
public:
	NetworkInit()
	{
		// 1. 네트워크 라이브러리 초기화
		WSADATA w;
		WSAStartup(0x202, &w);
	}
	~NetworkInit()
	{
		// 6. socket 라이브러리 cleanup
		WSACleanup();
	}
};
// IP 주소를 관리하는 클래스
class IPAddress
{
	SOCKADDR_IN addr;
public:
	IPAddress(const char* ip, short port)
	{
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
	}
	SOCKADDR* getRawAddress()
	{
		return (SOCKADDR*)&addr;
	}
};

// Socket 작업을 책임지는 클래스
class Socket
{
	int sock;
public:
	Socket(int type) { sock = socket(PF_INET, type, 0); }

	void Bind(IPAddress* ip)
	{
		::bind(sock, ip->getRawAddress(), sizeof(SOCKADDR_IN));
	}
	void Listen() { ::listen(sock, 5); }

	void Accept()
	{
		struct sockaddr_in addr2 = { 0 };
		int sz = sizeof(addr2);

		accept(sock, (SOCKADDR*)&addr2, &sz);
	}
};

// TCPServer 를 만들려면
// 1. 몇개의 클래스를 사용해서
// 2. 몇단계의 절차를 거쳐야 합니다.
// => 이런 과정을 단순화 하는 상위레벨의 클래스를 제공합니다. - Facade 계층

class TCPServer
{
	NetworkInit init;
	Socket sock{ SOCK_STREAM }; // TCP 서버
public:
	void Start(const char* sip, short port)
	{
		IPAddress addr(sip, port);
		sock.Bind(&addr);
		sock.Listen();
		sock.Accept();
	}
};


int main()
{
	// 라이브러리에 위 같은 TCSPServer 가 있다면 최종 사용자는 아래처럼
	// 사용하면 됩니다. 아주 사용하기 쉬운 라이브러리가 되었습니다!!!
	TCPServer server;
	server.Start("127.0.0.1", 3000);

}