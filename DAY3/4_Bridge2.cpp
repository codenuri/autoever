#include <iostream>

// bridge 패턴
// => 구현과 추상(사용자가 사용하는 코드)를 분리해서 상호 독립적인 update 가
//    가능하게 한다.

// => 사용자가 추상층을 사용하면 구현층을 UPDATE 해도 사용자 코드는 변경되지 않는다

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

// 간접층을 도입 하면 "유연성"이 증가 된다.
// "구현을 직접 사용하지 말고 추상층(Bridge) 를 사용하게 한다."

// 사용자는 아래 클래스를 사용하게 됩니다.
// 그런데, 아래 클래스는 기능을 구현하지는 않습니다.
// 단지, 중간층 역활만 합니다.
class MP3
{
	IMP3* impl;
public:
	MP3(IMP3* p = nullptr) : impl(p) 
	{
		if (impl == nullptr)
			impl = new IPod;
	}
	void play() { impl->play(); }
	void stop() { impl->stop(); }

	// 구현층을 수정하지 않고도, 사용자들에게
	// 새로운 서비스 제공가능
	void play_one_minute()
	{
		impl->play();

		// 1분간 타이머 설정후
		impl->stop();
	}
};


class People
{
public:
//	void use(IMP3* p) // 구현층을 직접 사용
	void use(MP3* p)  // 간접층(추상층)을 사용	
	{
		p->play();
		p->stop();

		p->play_one_minute();
	}
};


int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


