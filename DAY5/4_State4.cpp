#include <iostream>

// ��� 3. ���ϴ� ���� �ٸ� Ŭ������!!!

// ������ȹ�濡 ���� ĳ������ ��� ������ ����ȴ�.
struct IAction
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IAction() {}

	// �̿ܿ� jump, slide, fly �� ĳ������ ��� ������ �������̽��� ���
};

// ĳ������ ���۸� ���� Ŭ������ ���� �մϴ�.(���°� ���� ����(�Լ�)�� �ִ� Ŭ����)

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
// �ϳ��� ���� "run" �� 3������ ������ �Ǿ����ϴ�.
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
		action = &a2; // ��� ������ �����մϴ�.
					  // �̼���, ��ü�� ��� ��� �Լ��� �ѹ��� ��ü �˴ϴ�.
					  // ���´� ���� ������
					  // ��ġ �ٸ� Ŭ������ ����ϴ� �Ͱ� ���� ȿ���Դϴ�.
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



