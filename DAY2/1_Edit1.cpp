#include <iostream>
#include <string>
#include <conio.h>

// �Է°��� ��ȿ���� Ȯ���ϴ� Validation ����� �߰��� ���ô�.

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

			if (c == 13) break; // enter Ű

			if (isdigit(c))	// ���� ��ȿ���� Ȯ��
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



