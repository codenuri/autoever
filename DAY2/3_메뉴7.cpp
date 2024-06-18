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
		std::cout << get_title() << " 메뉴 선택\n";
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
			std::cout << sz + 1 << ". 종료\n";
			std::cout << "메뉴를 선택하세요 >> ";

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
	
	root->add(new PopupMenu("확대/축소")    );
	root->add(new MenuItem("상태표시줄", 11));


	// 아래 코드에 대해서 생각해 봅시다.
//	root->get_submenu(0)->add( new MenuItem("확대", 21) );
				// error. add() 함수는 PopupMenu 에 있는 멤버 함수. 
				// get_submenu(0) 의 반환 타입은 BaseMenu*

	// 해결책 #1. 캐스팅해서 add 를 사용한다.
	static_cast<PopupMenu*>(root->get_submenu(0))->add(new MenuItem("확대", 21));


	// 해결책 #2. 캐스팅없이 add 를 호출하려면 어떻게 해야 할까 ?
	//            좋은 디자인 일까 ??
	//			  다음 예제(메뉴8.cpp) 에서... 

	root->command();
}



