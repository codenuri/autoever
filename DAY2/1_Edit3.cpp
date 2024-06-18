#include <iostream>
#include <string>
#include <conio.h>

// ���ؾ� �ϴ� �κ��� �и��ϴ� 2���� ���
// 1. ���ؾ� �ϴ� ���� �����Լ��� �и� �Ѵ� - Edit2.cpp
// 2. ���ؾ� �ϴ� ���� �ٸ� Ŭ������ �и� �Ѵ�. - Edit3.cpp


// Validation ��åŬ������ ���� �������̽�
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }
	virtual ~IValidator() {}
};

// �ֹε�Ϲ�ȣ : 991    1    Ȯ��




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

			if (c == 13) break; 

			if ( isdigit(c) )	
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



