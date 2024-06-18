#include <iostream>
#include <string>
#include <conio.h>

// 변해야 하는 부분을 분리하는 2가지 기술
// 1. 변해야 하는 것을 가상함수로 분리 한다 - Edit2.cpp
// 2. 변해야 하는 것을 다른 클래스로 분리 한다. - Edit3.cpp


// Validation 정책클래스에 대한 인터페이스
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }
	virtual ~IValidator() {}
};

// 주민등록번호 : 991    1    확인


class Edit
{
	std::string data;

	//-----------------------------------
	IValidator* val = nullptr;
public:
	void set_validator(IValidator* v) { val = v; }
	//-----------------------------------


	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13 && (val == nullptr || val->is_complete(data))  ) break;

			if ( val == nullptr || val->validate(data, c) ) // 값의 유효성 확인을
			{												// 다른 객체에 위임.
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



