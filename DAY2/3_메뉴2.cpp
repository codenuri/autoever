#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// ��ü���� ���α׷��� 
// => ��� ���� ��ü�̴�.!
// => �ʿ��� Ÿ���� ���� ���� �Ѵ�.

// �޴��׸� �Ѱ��� ��Ÿ���� Ŭ����
class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	const std::string& get_title() const { return title; }

	// �޴� ���ý� ȣ��Ǵ� �Լ�
	void command()
	{
		std::cout << get_title() << " �޴� ����\n";
		_getch();
	}
};

int main()
{
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);

	m1.command(); // �޴� ���ý� ȣ��ȴٰ� ����. 
}




