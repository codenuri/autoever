#include <iostream>

// 방법 3. 변하는 것을 다른 클래스로!!!

// 아이템획득에 따라 캐릭터의 모든 동작은 변경된다.
struct IAction
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IAction() {}

	// 이외에 jump, slide, fly 등 캐릭터의 모든 동작을 인터페이스로 약속
};

// 캐릭터의 동작만 가진 클래스를 설계 합니다.(상태가 없고 동작(함수)만 있는 클래스)

class NoItem : public IAction
{
public:
	void run()    override { std::cout << "run\n"; }
	void attack() override { std::cout << "attack\n"; }
};

class RedItem : public IAction
{
public:
	void run()    override { std::cout << "fast run\n"; }
	void attack() override { std::cout << "power attack\n"; }
};

class BlueItem : public IAction
{
public:
	void run()    override { std::cout << "very fast run\n"; }
	void attack() override { std::cout << "very power attack\n"; }
};
// 하나의 동작 "run" 도 3가지로 가지게 되었습니다.
// 

class Charater
{
	NoItem a1;
	RedItem a2;
	BlueItem a3;

	IAction* action = &a1;

	int gold;
	int item;
public:
	void run()    { action->run(); }
	void attack() { action->attack(); }

	void acquire_item()
	{
		action = &a2; // 모든 동작을 변경합니다.
					  // 이순간, 객체의 모든 멤버 함수가 한번에 교체 됩니다.
					  // 상태는 유지 되지만
					  // 마치 다른 클래스를 사용하는 것과 같은 효과입니다.
	}
};

int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();
	
	p->acquire_item();
	p->run();
	p->attack();

}

// strategy 와 state 는 class diagram 이 동일합니다.!!

// strategy : 객체가 사용하는 "알고리즘"의 교체

// state    : 객체의 내부 상태에 따른 모든(대부분의) 동작을 교체


// 자판기를 생각해 봅시다.
// => 모든 함수가
// => "동전을 넣었을때", "넣지 않았을때" 다르게 동작해야 합니다.

// 따라서, 동전이 있을때와 없을때의 동작을 담은 클래스를 각각 설계하고
// "동전 투입" 여부에 따라 모든 동작이 변경되게 해야 합니다.
class VendingMachine
{
public:
	void 선택_button() {}
	void 환불_button() {}
};

