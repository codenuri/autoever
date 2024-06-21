#include <iostream>

// Chain of resposibility(å���� ��)
// => ���� ���Ǵµ�, �̸��� �˷����� ���� ����.

// �Ʒ� �ڵ尡 "å���� ��" ������ �ٽ� �Դϴ�.
struct Handler
{
	Handler* next = nullptr;

	void Handle(int problem)
	{
		// #1. �ڽ��� ���� ó���� �õ�, �ڽ��� �����Լ� ȣ��
		if (HandleRequest(problem) == true)	// ó���Ǿ����� ��û ����!
			return;

		// #2. ������ �ذ���� ���� ���, ���� ��ü���� ����
		if (next != 0)
			next->Handle(problem);
	}

	virtual bool HandleRequest(int problem) = 0;
};

class Team1 : public Handler
{
public:
	bool HandleRequest(int problem) override 
	{
		std::cout << "start Team1\n";
		
		if (problem == 7)
		{
			std::cout << "resolved by Team1\n";
			return true;
		}
		return false;
	}
};
class Team2 : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "start Team2\n";

		if (problem % 2 == 0)
		{
			std::cout << "resolved by Team2\n";
			return true;
		}
		return false;
	}
};

class Team3 : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "start Team3\n";

		if (problem > 20)
		{
			std::cout << "resolved by Team3\n";
			return true;
		}
		return false;
	}
};
int main()
{
	Team1 t1;
	Team2 t2;
	Team3 t3;
	
	// ��û�� ó���ϴ� ���� ( Team1 => Team2 => Team3 )
	t1.next = &t2;
	t2.next = &t3;
	t3.next = nullptr;

//	t1.Handle(7);	// t1 �� �ذ�
//	t1.Handle(4);   // t1 -> t2.. �ذ�
//	t1.Handle(21);  // t1 -> t2 -> t3 �ذ�
	t1.Handle(13);  // �ƹ��� �ذ� ����..
}


