#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

class Window
{
	int handle;

	inline static std::map<int, Window*> this_map;


	Window* parent = nullptr;		   // 부모는 한개
	std::vector<Window*> child_vector; // 자식은 여러개
public:
	void add_child(Window* child)
	{
		child_vector.push_back(child);
		child->parent = this;
		// C 함수로 실제 자식윈도우로 부착
		ec_add_child(this->handle, child->handle);
	}


	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);

		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN:
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


class MainWindow : public Window
{
public:
	void lbutton_down() override { std::cout << "MainWindow lbutton_down()\n"; }
};

class ChildWindow : public Window
{
public:
	void lbutton_down() override { std::cout << "ChildWindow lbutton_down()\n"; }
};


int main()
{
	MainWindow w;
	w.create("A");

	ChildWindow c;
	c.create("A");

	w.add_child(&c); // c 를 w 의 자식으로 부착

	ec_process_message();

}