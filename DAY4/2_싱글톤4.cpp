#include <iostream>
#include <mutex>

// 오직 한개의 객체를 "힙 에 생성" 하는 모델!
// => 동기화 추가
// => RAII 기술 적용 - std::lock_guard !!


// RAII (C++ Idioms) 기술의 핵심
// => 자원의 반납은 "함수의 마지막 부분" 에서 하는 것이 아니라!!
// => 생성자/소멸자에 의존해서 관리되어야 한다는 것
// 
// => "Resource Acquision Is Initialization"
//     자원을 획득하게 되는 것은 (자원관리 객체가) 초기화 될때이다.
//     생성자에서 자원을 획득하게 된다는 것을 의미!



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
		{
			std::lock_guard<std::mutex> g(mtx); // C++ 표준에 이미 std::lock_guard 있습니다.
//			lock_guard<std::mutex> g(mtx);	// 1. g의 생성자에서 "mtx.lock()" 수행
			//		mtx.lock();				// 2. g가 파괴될때 소멸자에서 "mtx.unlock()"
											// 3. 함수 수행중 예외등이 발생해도
											//    지역변수(g) 의 파괴는 안전하게 보장됩니다.
											//    g의 소멸자는 호출된다는 의미
											//    => stack unwinding 이라고 합니다.
			if (sinstance == nullptr)
				sinstance = new Cursor;

			//		mtx.unlock();
		} // <== g 파괴, 즉, 여기서 unlock

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




