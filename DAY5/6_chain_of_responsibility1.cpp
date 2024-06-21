#include <iostream>

// Chain of resposibility(책임의 고리)
// => 많이 사용되는데, 이름이 알려지지 않은 패턴.

// 아래 코드가 "책임의 고리" 패턴의 핵심 입니다.
struct Handler
{
	Handler* next = nullptr;

	void Handle(int problem)
	{
		// #1. 자신이 먼저 처리를 시도, 자신의 가상함수 호출
		if (HandleRequest(problem) == true)	// 처리되었으면 요청 종료!
			return;

		// #2. 문제가 해결되지 않은 경우, 옆의 객체에게 전달
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
	
	// 요청을 처리하는 순서 ( Team1 => Team2 => Team3 )
	t1.next = &t2;
	t2.next = &t3;
	t3.next = nullptr;

//	t1.Handle(7);	// t1 이 해결
//	t1.Handle(4);   // t1 -> t2.. 해결
//	t1.Handle(21);  // t1 -> t2 -> t3 해결
	t1.Handle(13);  // 아무도 해결 못함..
}


