// 7_�̱���1 - 123 page
#include <iostream>

// �̱��� : ���� �Ѱ��� ��ü�� �����ϴ� ��.
//		    ��𼭵��� ������ ������� ��ü�� �����Ҽ� �ְ� �ϴ� ����

// => �ᱹ "��������" �� ������ ����.
// => �׷���, ���������� "���� ���� �ڵ�" �Դϴ�.
// => �׷���, "�̱��� ����" �� ���� ���ǵ� ���� �ֽ��ϴ�.



// Cursor �� �̱������� �Ϸ��� �Ʒ� ��Ģ ��� �ڵ带 �ۼ��ϸ� �˴ϴ�.

class Cursor
{
	// ��Ģ #1. �����ڸ� private ��!!
private:
	Cursor() {}

	// ��Ģ #2.

	// ��Ģ #3. ���� �Ѱ��� ��ü�� ���� ��ȯ�ϴ� static ��� �Լ�
public:
	static Cursor& get_instance()
	{
		static Cursor instance;
		return instance;
	}
};

int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

	// c1, c2 �� ���ϰ�ü�� ����Ű�� ���� �Դϴ�
	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;
}








