#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	const std::string& get_title() const { return title; }

	virtual void command() = 0;
};






class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		std::cout << get_title() << " �޴� ����\n";
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:

	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add(BaseMenu* m) { v.push_back(m); }



	void command()
	{
		while (1)
		{
			system("cls");

			auto sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << '\n';
			}
			std::cout << sz + 1 << ". ����\n";
			std::cout << "�޴��� �����ϼ��� >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;


			v[cmd - 1]->command();
		}
	}

	BaseMenu* get_submenu(int idx) { return v[idx]; }
};


int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	
	root->add(new PopupMenu("Ȯ��/���")    );
	root->add(new MenuItem("����ǥ����", 11));


	// �Ʒ� �ڵ忡 ���ؼ� ������ ���ô�.
//	root->get_submenu(0)->add( new MenuItem("Ȯ��", 21) );
				// error. add() �Լ��� PopupMenu �� �ִ� ��� �Լ�. 
				// get_submenu(0) �� ��ȯ Ÿ���� BaseMenu*

	// �ذ�å #1. ĳ�����ؼ� add �� ����Ѵ�.
	static_cast<PopupMenu*>(root->get_submenu(0))->add(new MenuItem("Ȯ��", 21));


	// �ذ�å #2. ĳ���þ��� add �� ȣ���Ϸ��� ��� �ؾ� �ұ� ?
	//            ���� ������ �ϱ� ??
	//			  ���� ����(�޴�8.cpp) ����... 

	root->command();
}



