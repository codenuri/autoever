// 이 소스는 "32bit(x86)" 으로 빌드 해야 합니다.
// 

// Server1.cpp
#define USING_GUI
#include "cppmaster.h" // IPC 기능 관련 함수가 이헤더에 있습니다.

class Server
{
public:
	int Add(int a, int b) { return a + b; }
	int Sub(int a, int b) { return a - b; }
};
Server server;


int handler(int code, int a, int b)
{
	printf("메세지 도착 : %d, %d, %d\n", code, a, b);
	switch (code)
	{
	case 1: return server.Add(a, b); // 이 함수의 반환값은
	case 2: return server.Sub(a, b); // Client 에게 전달됩니다.
	}
	return 0;
}
int main()
{
	// IPC 서버로 시작 ( 아래 함수가 cppmaster.h 에 있습니다)
	ec_start_server("Calc",		// "서버이름"
					&handler);	// 클라이언트 접속시 호출될 함수
								// 클라이언트는 서버에 int 값 3개를 전달
								// 하게 됩니다.
}




