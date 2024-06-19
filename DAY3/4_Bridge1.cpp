// 6_Bridge1 - 90 page
#include <iostream>

struct IMP3
{
	virtual void play() = 0;
	virtual void stop() = 0;
	virtual ~IMP3() {}
};

class IPod : public IMP3
{
public:
	void play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void stop() { std::cout << "Stop" << std::endl; }
};

class People
{
public:
	void use(IMP3* p)	// 약한 결합 : 다양한 MP3 제품 사용가능
//	void use(IPod* p)	// 강한 결합 : 한가지 제품(IPod)만 사용가능. 경직된 디자인
	{
		p->play();
		p->stop();

		// 그런데, "1분 미리듣기" 기능이 필요하다.
		p->play_one_minute();

		// 요구되는 기능을 제공하려면 "인터페이스(IMP3)" 를 수정해야 한다.
		// => 인터페이스를 변경하는 것은 기존의 모든 제품을 수정해야 한다.
	}
};


int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


