#include <iostream>

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;	

public:
	// ���� : �Ʒ� �ڵ�� ��Ƽ�����忡 �����ұ�� ???
	// => ������ �����尡 �Ʒ� �Լ��� ���ÿ� �����Ҷ�!!!
	//    ���� �Ѱ��� ��ü���� �����Ҽ� ������� ?
	// => C++11 ���� �����մϴ�. static ���������� �ʱ�ȭ(������ ȣ��)��
	//	  �ڵ����� ����ȭ �˴ϴ�.(���������δ� "spinlock" ����� ����ȭ)

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

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

}





