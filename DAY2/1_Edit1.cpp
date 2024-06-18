#include <iostream>
#include <string>
#include <conio.h>

// 입력값의 유효성을 확인하는 Validation 기능을 추가해 봅시다.

class Edit
{
	std::string data;
public:
	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; // enter 키

			if (isdigit(c))	// 값의 유효성을 확인
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};



int main()
{
	Edit e;

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}



