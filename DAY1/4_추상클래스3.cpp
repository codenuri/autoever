#include <iostream>

// PC �� USB �޸𸮴� "OCP" �� �����մϴ�.
// => PC �� USB ���̿� ���Ѿ� �ϴ� ��Ģ �� �ֱ� ������ �����մϴ�.
// => H/W �� ��κ� OCP �� �����մϴ�.

// S/W ���迡���� "��Ģ(�������̽�)" �� ���� ���� �ϴ� ���� �����ϴ�.



// ��� ī�޶� ���Ѿ� �ϴ� ��Ģ�� ���� ����
// ��Ģ : ��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ� �Ǿ�� �Ѵ�.

class ICamera
{
public:
	virtual void take() = 0;
};

// ���� ���� ī�޶�� ���, ��Ģ�� �ֽ��ϴ�.
// ����ڴ� ��Ģ ��θ� ����ϸ� �˴ϴ�.

class People
{
public:
	// �ٽ� ; Camera, HDCamera ���� ��ü���� ��ǰ�� �������� ����!!
	//        ��Ģ(�������̽�)�� �����ؼ� ����մϴ�. (DIP ����)
	void use_camera(ICamera* c) { c->take(); }
};

// ���� "ī�޶� ���鶧�� �ݵ�� ��Ģ"�� ���Ѿ� �մϴ�.
class Camera : public ICamera
{
public:
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc);

	UHDCamera uhc;
	p.use_camera(&uhc); // ok!!! ���ο� ī�޶� ���������
						// People �� ������ �ʿ� ����.
}






