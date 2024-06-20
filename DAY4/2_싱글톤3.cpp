#include <iostream>
#include <mutex>

// 오직 한개의 객체를 "힙 에 생성" 하는 모델!
// => 동기화 추가

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;


	static Cursor* sinstance;
	static std::mutex mtx;
public:
	static Cursor& get_instance()
	{
		mtx.lock();

		if (sinstance == nullptr)
			sinstance = new Cursor;

		mtx.unlock();

		return *sinstance;
	}
};
Cursor* Cursor::sinstance = nullptr;
std::mutex Cursor::mtx;





int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

}




