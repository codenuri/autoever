#define USING_GUI
#include "cppmaster.h"
#include <map>


// GUI 라이브러리를 C++로 만들어 봅시다.
class Window
{
	int handle;
	
	inline static std::map<int, Window*> this_map;
				// <윈도우 번호, this> 를 보관하기 위한 자료구조

public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);

		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];
		
		// 이제 self 를 this 처럼 생각하고 사용하면됩니다.
		// 그러면 static 멤버 함수에서도 모든 멤버 접근 가능합니다.
		switch (msg)
		{
		case WM_LBUTTONDOWN: 
			//lbutton_down();		// this->lbutton_down();
			self->lbutton_down();
			break;

		case WM_KEYDOWN:     
			self->key_down(); 
			break;
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