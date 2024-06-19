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
	void use(IMP3* p)	// ���� ���� : �پ��� MP3 ��ǰ ��밡��
//	void use(IPod* p)	// ���� ���� : �Ѱ��� ��ǰ(IPod)�� ��밡��. ������ ������
	{
		p->play();
		p->stop();

		// �׷���, "1�� �̸����" ����� �ʿ��ϴ�.
		p->play_one_minute();

		// �䱸�Ǵ� ����� �����Ϸ��� "�������̽�(IMP3)" �� �����ؾ� �Ѵ�.
		// => �������̽��� �����ϴ� ���� ������ ��� ��ǰ�� �����ؾ� �Ѵ�.
	}
};


int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


