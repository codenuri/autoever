#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


class UnsupportedOperation {};


class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	const std::string& get_title() const { return title; }

	virtual void command() = 0;

	// 아래 2개의 함수는 PopupMenu 에만 필요하고,  MenuItem 에서는 필요 없습니다.
	// 하지만 BaseMenu 에서 제공해주면 아래처럼 캐스팅 없이 사용가능합니다
	// root->get_submenu(0)->add(....)

	// 기본 구현은 예외 발생으로 !!
	virtual void add(BaseMenu*) { throw UnsupportedOperation(); }
	virtual BaseMenu* get_submenu(int idx) { throw UnsupportedOperation(); }
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

	root->add(new PopupMenu("확대/축소"));
	root->add(new MenuItem("상태표시줄", 11));


	// 핵심 : add 가 BaseMenu* 에도 있으므로 아래처럼 캐스팅 없이 사용가능

	root->get_submenu(0)->add( new MenuItem("확대", 21) );


	// 아래 코드는 MenuItem 객체에 대해서 add 호출 => 예외 발생!!
	try
	{
		root->get_submenu(1)->add(new MenuItem("확대", 21));
	}
	catch (const UnsupportedOperation& e)
	{
		std::cout << "예외 발생됨\n";
		std::exit(0);
	}
	root->command();
}

// 메뉴7.cpp : 안전성(safety) 를 중시하는 모델.
//			   개발자가 직접 캐스팅하므로 불편하지만..
//             캐스팅을 통해서 보다 명확하게 코드를 작성(개발자의 의도가 코드에 표현됨)

// 메뉴8.cpp : 편의성(confortable) 을 중시하는 모델
//				캐스팅이 없으므로 편리하다.
//				잘못사용하는 경우 예외 발생. 

// 메뉴8번은 결국 "복합객체(PopupMenu)" 와 "개별객체(MenuItem)" 의 사용법을
// 동일시하는 특징이 있습니다.



