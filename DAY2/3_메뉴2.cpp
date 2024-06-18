#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 객체지향 프로그래밍 
// => 모든 것은 객체이다.!
// => 필요한 타입을 먼저 설계 한다.

// 메뉴항목 한개를 나타내는 클래스
class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	const std::string& get_title() const { return title; }

	// 메뉴 선택시 호출되는 함수
	void command()
	{
		std::cout << get_title() << " 메뉴 선택\n";
		_getch();
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	m1.command(); // 메뉴 선택시 호출된다고 가정. 
}




