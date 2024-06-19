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

// Proxy ������ : Server ������
// Proxy ����� : Client ������

int main()
{
	// Client �� �Ʒ�ó�� Proxy �̸��� ���� ����ϸ� "���� ����" �Դϴ�.
	// Proxy �� Update �Ǹ� �Ʒ� �ڵ�� �����Ǿ�� �մϴ�.
	// Client �� Proxy ���� "���� ����" ���� ����ؾ� �մϴ�.
	Calc* calc = new Calc; // ���� �ڵ�
							// �ذ��� Proxy4.cpp

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;
}





