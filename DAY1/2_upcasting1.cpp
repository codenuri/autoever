class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;

	Dog* p1 = &d;		// ok
	
//	int* p2 = &d;		// error. 관련 없는 타입의 포인터!!
	
	// 핵심 #1. 기반 클래스 타입의 포인터에 파생 클래스 객체의 주소를
	//		    담을수 있다.
	// => "upcasting" 이라고 합니다.
	// => 가능한 이유는 "Dog 객체 안에는 Animal도 존재" 합니다.

	Animal* p3 = &d;  // ok


	// 핵심 #2. "Animal*" 인 p3 로는 Animal 의 멤버만 접근 할수 있다.
	// => "Dog 가 추가" 한 멤버는 접근 안됨.

	p3->age   = 10; // ok
//	p3->color = 10; // error


	// 핵심 #3. "Animal* p3" 로 Dog 고유 멤버에 접근하려면
	//          캐스팅 해야 합니다.
	// => static_cast 또는 dynamic_cast 사용

	static_cast<Dog*>(p3)->color = 10;
					// => 단, 이경우 p3 가 가리키는 객체가 Dog라는
					//	  보장이 있어야 합니다.
					//    Dog 가 아니면 "미정의 동작 발생"

	// p3 가 가리키는 곳이 Dog 인지 조사할수 없나요 ??
	// => dynamic_cast 사용

}











