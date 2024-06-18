#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 이번 단계 까지의 핵심
// => 메뉴 하나 하나를 "객체" 로 만든다는 관점 => "객체지향" 프로그래밍
// => MenuItem, PopupMenu 클래스를 설계 해서 사용하는 관점. 


class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	const std::string& get_title() const { return title; }

	void command()
	{
		std::cout << get_title() << " 메뉴 선택\n";
		_getch();
	}
};

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}

	void add(MenuItem* m) { v.push_back(m); }

	// PopupMenu 선택시.. 
	void command()
	{
		while (1)
		{
			system("cls"); // 화면 지우기

			auto sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << '\n';
			}
			std::cout << sz + 1 << ". 종료\n";
			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)	// "종료" 메뉴 선택
				break;

			if (cmd < 1 || cmd > sz + 1) // 잘못된 입력
				continue;


			v[cmd - 1]->command();
		}
	}
};









int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	PopupMenu pm("오늘의 점심");
	 
	pm.add(&m1);
	pm.add(&m2);

	pm.command();	// 팝업메뉴 선택시 해야 할일을 생각해 보세요
}




