// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.
//		    어디서든지 동일한 방법으로 객체에 접근할수 있게 하는 패턴

// => 결국 "전역변수" 와 유사한 개념.
// => 그런데, 전역변수는 "좋지 않은 코드" 입니다.
// => 그래서, "싱글톤 패턴" 에 대한 비판도 많이 있습니다.



// Cursor 를 싱글톤으로 하려면 아래 규칙 대로 코드를 작성하면 됩니다.

class Cursor
{
	// 규칙 #1. 생성자를 private 에!!
private:
	Cursor() {}

	// 규칙 #2. 컴파일러에게 복사 생성자를 만들지 못하도록..
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;	// 복사를 금지하면
												// 대입도 같이 금지 하는 것이
												// 일반적인 코딩 관례 입니다.

	// 규칙 #3. 오직 한개의 객체를 만들어서 반환하는 static 멤버 함수
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

	// c1, c2 는 동일객체를 가리키는 참조 입니다
	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

	// 아래 처럼 객체를 생성하는 것도 안되게 해야 합니다.
//	Cursor c3 = c1; // 복사 생성자!!
}


// 위 코드는 "오직 한개의 객체가 static 지역변수" 입니다.
// 
// => effective-c++ 의 저자인 scott-mayer 가 제안한 코드 입니다.
// => 흔히 "mayer's singleton" 이라고 부릅니다.
// => 특징 : "오직 한개의 객체가 static 지역변수"
// => C++ 진영에서 "가장 좋은 싱글톤 코드" 로 알려져 있습니다.






