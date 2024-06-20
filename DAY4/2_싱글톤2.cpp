// 7_½Ì±ÛÅæ1 - 123 page
#include <iostream>

// ¿ÀÁ÷ ÇÑ°³ÀÇ °´Ã¼¸¦ "Èü ¿¡ »ý¼º" ÇÏ´Â ¸ðµ¨!

class Cursor
{
	
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;	

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

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

}




