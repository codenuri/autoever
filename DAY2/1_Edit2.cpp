#include <iostream>
#include <string>
#include <conio.h>

// Validation ��å�� ����ڰ� �����Ҽ� �־�� �Ѵ�.

// ���뼺�� �������� �и�
// ������ ���� �ڵ忡�� ���ؾ� �ϴ� �κ��� �ִٸ�
// => ���ϴ� �κ��� �и��Ѵ�.
// => ���ϴ� �ڵ带 ������ �����Լ��� �и��Ѵ�.

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

			if ( validate(c) ) // ���ؾ� �ϴ� �κ��� �����Լ��� �и�!
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// ���� Validation ��å�� �����Ϸ��� Edit �� �Ļ� Ŭ������ ����
// ��ӵ� �����Լ�(validate) �� override �ϸ� �˴ϴ�.

// Edit �� ��ü�� �����ϴ� ���� �ƴ϶� Edit �� Ȯ���ؼ� Validation ��å ����

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
	NumEdit e;		// e�� Validation ��å�� �����Ҷ� ���� �ȵ�.
	AddressEdit e2;	// e�� ��å�� ����Ȱ��� �ƴ϶�..
					// �ٸ� ��å�� ���� ���ο� edit !!!

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


