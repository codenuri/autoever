#include <iostream>

class Animal
{
public:
	// non-virtual : 함수 호출시 static binding 하라는 의미(디폴트 바인딩정책)
	// => 컴파일 시간에 포인터 타입으로 결정
	void cry1() { std::cout << "Animal Cry1" << std::endl; }


	// virtual :  함수 호출시 dynamic binding 해달라는 의미
	// => 실행시 메모리 조사후 호출
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; }
};

class Dog : public Animal
{
public:
	void cry1()         { std::cout << "Dog Cry1" << std::endl; }
	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; }
};

int main()
{
	Dog d;    

	Animal* p = &d;

	p->cry1();	// static binding.  Animal Cry1    call Animal::cry1
	p->cry2();  // dynamic binding  Dog Cry2	   메모리 조사하는 기계어 코드
				//									call 조사결과에 따른함수
}
