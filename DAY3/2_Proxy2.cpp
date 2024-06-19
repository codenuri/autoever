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
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// ���� ���� ������ ������(Proxy)�� ������
// 1. Client �����ڴ� IPC ����� ���� �˴ϴ�.
// 2. "1, 2" �� ���� ��� �ڵ� ��� "Add, Sub" �Լ��� ����ϸ� �˴ϴ�.
// 3. ��� ó���� Proxy �� ����ϸ� �˴ϴ�.
// 
// 4. ���� ���Ǵ� ��û�� "ĳ��" ����� �����ص� �˴ϴ�.

// Proxy�� ���ؼ� �پ��� ����� �����Ҽ� �ֽ��ϴ�

int main()
{
	Calc* calc = new Calc;

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;
}





