#include <iostream>
#include <string>
#include <conio.h>

// Validation 정책은 사용자가 변경할수 있어야 한다.

// 공통성과 가변성의 분리
// 변하지 않은 코드에서 변해야 하는 부분이 있다면
// => 변하는 부분을 분리한다.
// => 변하는 코드를 별도의 가상함수로 분리한다.

class Edit
{
	std::string data;
public:

	virtual bool validate(char c)
	{
		return true;
	}


	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; 

			if ( validate(c) ) // 변해야 하는 부분을 가상함수로 분리!
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// 이제 Validation 정책을 변경하려면 Edit 의 파생 클래스를 만들어서
// 약속된 가상함수(validate) 를 override 하면 됩니다.

// Edit 의 자체를 변경하는 것이 아니라 Edit 를 확장해서 Validation 정책 변경

class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit e;
	NumEdit e;

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}



