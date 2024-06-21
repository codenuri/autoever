// 1_State1 - 182 page
#include <iostream>

// 방법 #1. 제어문 사용
// 단점 : 새로운 아이템 등장시 모든 동작 함수가 수정되어야 한다.
//        OCP 위반. 
class Charater
{
	int gold;
	int item;
public:
	void run()
	{ 
		if ( item == 1)
			std::cout << "run" << std::endl; 
		else if ( item == 2 )
			std::cout << "fast run" << std::endl;
	}
	void attack() 
	{ 
		if ( item == 1 )
			std::cout << "attack" << std::endl; 
		else if ( item == 2 )
			std::cout << "power attack" << std::endl;
	}
};

int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();
}



