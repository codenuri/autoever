#define USING_GUI
#include "cppmaster.h"



// GUI 라이브러리를 C++로 만들어 봅시다.
class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: lbutton_down() ; break;
		case WM_KEYDOWN:     key_down(); break;
		}
		return 0;
	}

	virtual void lbutton_down() {}
	virtual void key_down() {}
};

// 이제 라이브러리 사용자는 아래와 같은 클래스를 만들면 됩니다.
class MainWindow : public Window
{
public:
	void lbutton_down() override { std::cout << "MainWindow lbutton_down()\n"; }
};

int main()
{
	MainWindow w;
	w.create("A");

	ec_process_message();

}