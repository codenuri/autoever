#define USING_GUI
#include "cppmaster.h"

int msgproc(int hwnd, int msg, int a, int b)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON : " << hwnd << std::endl; break;
	case WM_KEYDOWN:     std::cout << "KEYDOWN : " << hwnd << std::endl; break;
	}
	return 0;
}

// GUI ���̺귯���� C++�� ����� ���ô�.
class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
	}
};


int main()
{
	Window w;
	w.create("A"); // �̼��� �����찡 �����Ǿ�� �մϴ�.

	ec_process_message();	

}