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
	Animal a;
	Dog d;

	Animal* p = &d;

//	if (사용자 입력 == 1) p = &a;

	// 핵심 #1. 컴파일시간에 컴파일러는 p가 가리키는 객체의 종류는
	//          알수 없다.(조사할수 없다.)
	// => 위 if 문 같은 코드가 있다면 실행시간에 p가 가리키는 곳이 "변경" 되므로         

	// 핵심 #2. 캐스팅의 종류
	// static_cast  : 컴파일 시간 캐스팅
	// dynamic_cast : 실행   시간 캐스팅

	// #1. static_cast : 컴파일 시간에 캐스팅
	// 장점 : 오버헤드가 전혀 없다. 빠르다.
	// 단점 : 객체를 조사할수 없다.

	p = &a; // p는 Animal 객체를 가리킨다.

	Dog* pdog = static_cast<Dog*>(p);	// 잘못된 캐스팅이지만
										// 조사할수 없으므로 그냥 주소가 나온다

	std::cout << pdog << std::endl; // 주소가 나온다!!
									// 단, 이주소는 사용하면 안됨..	
									// pdog 가 가리키는 곳은 Dog 가 아닌 Animal
}











