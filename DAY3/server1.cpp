// �� �ҽ��� "32bit(x86)" ���� ���� �ؾ� �մϴ�.
// 

// Server1.cpp
#define USING_GUI
#include "cppmaster.h" // IPC ��� ���� �Լ��� ������� �ֽ��ϴ�.

class Server
{
public:
	int Add(int a, int b) { return a + b; }
	int Sub(int a, int b) { return a - b; }
};
Server server;


int handler(int code, int a, int b)
{
	printf("�޼��� ���� : %d, %d, %d\n", code, a, b);
	switch (code)
	{
	case 1: return server.Add(a, b); // �� �Լ��� ��ȯ����
	case 2: return server.Sub(a, b); // Client ���� ���޵˴ϴ�.
	}
	return 0;
}
int main()
{
	// IPC ������ ���� ( �Ʒ� �Լ��� cppmaster.h �� �ֽ��ϴ�)
	ec_start_server("Calc",		// "�����̸�"
					&handler);	// Ŭ���̾�Ʈ ���ӽ� ȣ��� �Լ�
								// Ŭ���̾�Ʈ�� ������ int �� 3���� ����
								// �ϰ� �˴ϴ�.
}




