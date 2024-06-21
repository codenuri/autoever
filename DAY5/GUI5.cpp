#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

class Window
{
	int handle;

	inline static std::map<int, Window*> this_map;


	Window* parent = nullptr;		   // �θ�� �Ѱ�
	std::vector<Window*> child_vector; // �ڽ��� ������
public:
	void add_child(Window* child)
	{
		child_vector.push_back(child);
		child->parent = this;
		// C �Լ��� ���� �ڽ�������� ����
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
			self->fire_lbutton_down();
			break;

		case WM_KEYDOWN:
			self->key_down();
			break;
		}
		return 0;
	}

	void fire_lbutton_down()
	{
		// #1. �ڽ��� ���� ó���� �õ�
		if (lbutton_down() == true)
			return;

		// #2. ó������ ���� ��� �θ� �����찡 �ִٸ� �θ������쿡 ����
		if (parent != nullptr)
			parent->fire_lbutton_down();
	}


	virtual bool lbutton_down() { return false; }
	virtual void key_down() {}
};


class MainWindow : public Window
{
public:
	bool lbutton_down() override 
	{ 
		std::cout << "MainWindow lbutton_down()\n"; 
		return true;
	}
};




class ChildWindow : public Window
{
public:
	bool lbutton_down() override 
	{ 
		std::cout << "ChildWindow lbutton_down()\n"; 
		return true;
	}
};




int main()
{
	MainWindow w;
	w.create("A");

	ChildWindow c;
	c.create("A");

	w.add_child(&c); 

	ec_process_message();

}