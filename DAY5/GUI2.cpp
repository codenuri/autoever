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

// GUI 라이브러리를 C++로 만들어 봅시다.
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
	w.create("A"); // 이순간 윈도우가 생성되어야 합니다.

	ec_process_message();	

}