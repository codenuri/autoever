#define USING_GUI
#include "cppmaster.h"

// Proxy1.cpp ó�� �����
// 
// 1. ��� Ŭ���̾�Ʈ �����ڰ� IPC ����� �˾ƾ� �Ѵ�.
// 2. �������ӿ� ���� ���ó���� ��� Ŭ���̾�Ʈ�� ���� �ؾ� �Ѵ�.

// Proxy        : �����ڸ� ����� ����
// remote-proxy : ������ ������ ���� ������

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

	std::cout << "���� ��ȣ : " << server << std::endl;


	
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





