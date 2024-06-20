#include <iostream>

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;	

public:
	// 질문 : 아래 코드는 멀티스레드에 안전할까요 ???
	// => 여러개 스레드가 아래 함수를 동시에 실행할때!!!
	//    오직 한개의 객체임을 보장할수 있을까요 ?

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





