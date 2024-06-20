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

	// ��Ģ #2. �����Ϸ����� ���� �����ڸ� ������ ���ϵ���..
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;	// ���縦 �����ϸ�
												// ���Ե� ���� ���� �ϴ� ����
												// �Ϲ����� �ڵ� ���� �Դϴ�.

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

	// �Ʒ� ó�� ��ü�� �����ϴ� �͵� �ȵǰ� �ؾ� �մϴ�.
//	Cursor c3 = c1; // ���� ������!!
}


// �� �ڵ�� "���� �Ѱ��� ��ü�� static ��������" �Դϴ�.
// 
// => effective-c++ �� ������ scott-mayer �� ������ �ڵ� �Դϴ�.
// => ���� "mayer's singleton" �̶�� �θ��ϴ�.
// => Ư¡ : "���� �Ѱ��� ��ü�� static ��������"
// => C++ �������� "���� ���� �̱��� �ڵ�" �� �˷��� �ֽ��ϴ�.






