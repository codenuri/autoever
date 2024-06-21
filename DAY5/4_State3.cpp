#include <iostream>

// ��� #2. ���ϴ� ���� �����Լ���...!
// => �����ۿ� ���� ������ ���ؾ� �Ѵ�.
// => ��� ���� �Լ��� �����Լ���!!
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

// �����ۿ� ���� ������ ���ؾ� �Ѵ�.
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

	p = new SuperItem; // ������ ȹ��
	p->run();
	p->attack();

}



