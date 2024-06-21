#define USING_GUI
#include "cppmaster.h"



// GUI 라이브러리를 C++로 만들어 봅시다.
class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window( msgproc, title );
	}

	// 아래처럼 non-static 멤버 함수로 만들면 "this"가 인자로 추가됩니다.
	// => 즉 인자가 "5개"인 함수처럼 됩니다.
	//int msgproc( int hwnd, int msg, int a, int b)


	// 아래처럼 해야 인자가 4개인 함수 포인터와 호환됩니다.
	// 아래 함수가 "static" 이어야 하는 이유를 명확히 알아야 합니다.
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
	w.create("A"); // 이순간 윈도우가 생성되어야 합니다.

	ec_process_message();	

}