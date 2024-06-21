#define USING_GUI
#include "cppmaster.h"



// GUI ���̺귯���� C++�� ����� ���ô�.
class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window( msgproc, title );
	}

	// �Ʒ�ó�� non-static ��� �Լ��� ����� "this"�� ���ڷ� �߰��˴ϴ�.
	// => �� ���ڰ� "5��"�� �Լ�ó�� �˴ϴ�.
	//int msgproc( int hwnd, int msg, int a, int b)


	// �Ʒ�ó�� �ؾ� ���ڰ� 4���� �Լ� �����Ϳ� ȣȯ�˴ϴ�.
	// �Ʒ� �Լ��� "static" �̾�� �ϴ� ������ ��Ȯ�� �˾ƾ� �մϴ�.
	static int msgproc(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: std::cout << "LBUTTON : " << hwnd << std::endl; break;
		case WM_KEYDOWN:     std::cout << "KEYDOWN : " << hwnd << std::endl; break;
		}
		return 0;
	}
};


int main()
{
	Window w;
	w.create("A"); // �̼��� �����찡 �����Ǿ�� �մϴ�.

	ec_process_message();	

}