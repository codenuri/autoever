// 32bit ȯ�濡�� �����ؾ� �մϴ�.
// => "X86" ���� ����
#define USING_GUI
#include "cppmaster.h"

// GUI ���α׷��� �����Ϸ���
// => �� OS �� C ��� ������� GUI ���� �Լ��� �����ϰ� �ֽ��ϴ�.
// => �ش� �Լ��� ����ϸ� �˴ϴ�. 

// �Ʒ� �ڵ�� 
// => C �� ����ؼ� GUI ���α׷��� ���� ����..!!
// => C �� ���� ����ϸ� �׻� ������ ���°� �˴ϴ�.
// => ���� ���� ����, ��ü���� ���̺귯���� ������ ���ô�.


// ������ �̺�Ʈ�� ó���ϴ� �Լ��� �ݵ�� ���ڰ� 4�� �̾�� �մϴ�.
int msgproc(int hwnd, int msg, int a, int b) 
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON : " << hwnd << std::endl; break;
	case WM_KEYDOWN:     std::cout << "KEYDOWN : " << hwnd << std::endl; break;
	}
	return 0;
}

int main()
{
	int h1 = ec_make_window(msgproc, // �����쿡�� �߻��� �̺�Ʈ�� ó�����Լ�
							"A");
	int h2 = ec_make_window(msgproc, "B");


	// �ڽ������� �����
	ec_add_child(h1, h2); // h2 �� h1 �� �ڽ�������� �����.


	ec_process_message();	// ���α׷��� ���� ���� ����
							// window ���� �߻��ϴ� �̺�Ʈ�� 
							// ������, ��ϵ� �Լ��� ������ �޶�
}

