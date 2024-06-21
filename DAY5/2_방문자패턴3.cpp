#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// list      : 선형 구조, 모든 요소가 같은 타입
// 
// PopupMenu : 트리 구조, 저장하는 요소가 다른 타입.
//						 (PopupMenu, MenuItem)


// 방문자 : 방문하는 요소 한개에 대한 연산을 정의!!
//         그런데, 요소의 타입이 다를수 있다.
class PopupMenu;
class MenuItem;

struct IMenuVisitor
{
	virtual void visit(PopupMenu*) = 0;
	virtual void visit(MenuItem*) = 0;
	virtual ~IMenuVisitor() {}
};








class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	void set_title(const std::string& s) { title = s; }

	virtual void command() = 0;
};




class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command() override
	{
		std::cout << get_title() << " 메뉴가 선택됨" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command() override
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			std::cout << sz + 1 << ". 종료" << std::endl;

			int cmd;
			std::cout << "메뉴를 선택하세요 >> ";
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1)
				break;

			v[cmd - 1]->command(); 
		}

	}

};



// 아래 코드가 "팝업메뉴의 타이틀을 변경하는 방문자" 입니다.
class PopupMenuTitleChangeVisitor : public IMenuVisitor
{
	std::string deco;
public:
	PopupMenuTitleChangeVisitor(const std::string& s) : deco(s) {}

	void visit(MenuItem*) override {} // MenuItem 방문시는 아무일도 안함

	void visit(PopupMenu* pm) override 
	{
		auto s = pm->get_title();

		s = s + deco;

		pm->set_title(s);
	}
};






int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	root->add_menu(pm2);


	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));

	// 모든 메뉴는 결국 root 가 보관합니다.
	// "root" 는 복합객체
	// 모든 메뉴를 방문해서, "PopupMenu" 인 경우만 title 을 변경하는
	// 방문자를 만들어 봅시다.
	PopupMenuTitleChangeVisitor pv("=>");
	root->accept(pv); // pv 가 모든 메뉴를 방문해서 주어진 연산 수행



	root->command();

}




