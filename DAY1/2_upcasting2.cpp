// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};

int main()
{
	// Upcasting 활용 #1. 동종을 보관하는 컨테이너 만들기.
	std::vector<Dog*>    v1; // Dog 객체만 보관하겠다는 의도!
	std::vector<Animal*> v2; // 동종(Animal 로 부터 파생된 모든 타입의 객체)
							 // 을 보관하겠다는 의도.
}