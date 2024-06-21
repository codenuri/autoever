#define USING_GUI
#include "cppmaster.h"
#include <map>


// GUI ���̺귯���� C++�� ����� ���ô�.
class Window
{
	int handle;
	
	inline static std::map<int, Window*> this_map;
				// <������ ��ȣ, this> �� �����ϱ� ���� �ڷᱸ��

public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);

		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];
		
		// ���� self �� this ó�� �����ϰ� ����ϸ�˴ϴ�.
		// �׷��� static ��� �Լ������� ��� ��� ���� �����մϴ�.
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

// ���� ���̺귯�� ����ڴ� �Ʒ��� ���� Ŭ������ ����� �˴ϴ�.
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