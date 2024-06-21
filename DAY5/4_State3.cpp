#include <iostream>

// 방법 #2. 변하는 것을 가상함수로...!
// => 아이템에 따라 동작은 변해야 한다.
// => 모든 동작 함수를 가상함수로!!
class Character
{
	int gold;
	int item;
public:
	void run()    { do_run(); }
	void attack() { do_attack(); }

	virtual void do_run() { std::cout << "run" << std::endl; }
	virtual void do_attack() { std::cout << "attack" << std::endl; }
};

// 아이템에 따라 동작은 변해야 한다.
class SuperItem : public Character
{
public:
	virtual void do_run() { std::cout << "fast run" << std::endl; }
	virtual void do_attack() { std::cout << "power attack" << std::endl; }
};

int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	p = new SuperItem; // 아이템 획득
	p->run();
	p->attack();

}



