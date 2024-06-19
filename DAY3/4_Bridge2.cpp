#include <iostream>

// bridge ����
// => ������ �߻�(����ڰ� ����ϴ� �ڵ�)�� �и��ؼ� ��ȣ �������� update ��
//    �����ϰ� �Ѵ�.

// => ����ڰ� �߻����� ����ϸ� �������� UPDATE �ص� ����� �ڵ�� ������� �ʴ´�

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

// �������� ���� �ϸ� "������"�� ���� �ȴ�.
// "������ ���� ������� ���� �߻���(Bridge) �� ����ϰ� �Ѵ�."

// ����ڴ� �Ʒ� Ŭ������ ����ϰ� �˴ϴ�.
// �׷���, �Ʒ� Ŭ������ ����� ���������� �ʽ��ϴ�.
// ����, �߰��� ��Ȱ�� �մϴ�.
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

	// �������� �������� �ʰ���, ����ڵ鿡��
	// ���ο� ���� ��������
	void play_one_minute()
	{
		impl->play();

		// 1�а� Ÿ�̸� ������
		impl->stop();
	}
};


class People
{
public:
//	void use(IMP3* p) // �������� ���� ���
	void use(MP3* p)  // ������(�߻���)�� ���	
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

