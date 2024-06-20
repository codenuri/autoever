#include <iostream>
#include <mutex>

// 오직 한개의 객체를 "힙 에 생성" 하는 모델!
// => 동기화 추가
// => RAII 기술 적용 - std::lock_guard !!


// RAII 기술의 핵심
// => 자원의 반납은 "함수의 마지막 부분" 에서 하는 것이 아니라!!
// => 생성자/소멸자에 의존해서 관리되어야 한다는 것

template<typename T>
class lock_guard
{
	T& mtx;
public:
	inline lock_guard(T& m) : mtx(m) { mtx.lock(); }
	inline ~lock_guard()             { mtx.unlock(); }
};


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
		lock_guard<std::mutex> g(mtx);
//		mtx.lock();

		if (sinstance == nullptr)
			sinstance = new Cursor;

//		mtx.unlock();

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




