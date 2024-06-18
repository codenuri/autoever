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

			if ( val == nullptr || val->validate(data, c) ) // ���� ��ȿ�� Ȯ����
			{												// �ٸ� ��ü�� ����.
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// ���� �Է°��� ��ȿ���� Ȯ���ϴ� �پ��� ������ Validator�� �����ϸ�˴ϴ�.

class LimitDigitValidator : public IValidator
{
	int limit;
public:
	LimitDigitValidator(int n) : limit(n) {}

	bool validate(const std::string& s, char c) override
	{
		return s.size() < limit && isdigit(c);
	}
};

int main()
{
	Edit e;
	LimitDigitValidator v1(5);
	e.set_validator(&v1);	// edit �� ���� ��ȿ���� Ȯ���ϴ� Validator ����.
							// edit �� v1 �� Validation ��å�� ����ؼ� �Է¹ް� �˴ϴ�.

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}



