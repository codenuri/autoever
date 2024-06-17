#include <iostream>

// PC �� USB �޸𸮴� "OCP" �� �����մϴ�.
// => PC �� USB ���̿� ���Ѿ� �ϴ� ��Ģ �� �ֱ� ������ �����մϴ�.
// => H/W �� ��κ� OCP �� �����մϴ�.

// S/W ���迡���� "��Ģ(�������̽�)" �� ���� ���� �ϴ� ���� �����ϴ�.


// �߻�Ŭ���� vs �������̽�
// ���� ���̽� : ���Ѿ� �ϴ� ��Ģ�� ���� ���
// �߻� Ŭ���� : ���Ѿ� �ϴ� ��Ģ�� ���� ��� +  �ٸ� ����� �ִ� ���

// java, C# : abstract, interface ��� ������ Ű���� ����
// C++      : ������ Ű���� ����, �߻� Ŭ���� �������� ��� ����..
//             ����, ���� Ư¡���� ���������θ� ����..

// ��� ī�޶� ���Ѿ� �ϴ� ��Ģ�� ���� ����
// ��Ģ : "��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ� �Ǿ�� �Ѵ�." ��� ǥ������ ����
//        "��� ī�޶�� �Ʒ� �������̽��� ���� �ؾ� �Ѵ�." ��� ǥ���ϴ� ���� �����ϴ�.

//class ICamera		// ���������ڸ� �����ϸ� private
struct ICamera		// ���������ڸ� �����ϸ� public
{	
//public:
	virtual void take() = 0;
	virtual ~ICamera() {}   // �������̽��� �ᱹ ���������δ� ��� Ŭ�����Դϴ�.
							// C++���� ��� Ŭ������ �Ҹ��ڴ� "virtual" �̾�� �մϴ�.
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


// ���� ����(tightly coupling)
// => People �� ī�޶� ����, "��ü���� ��ǰ�̸�(Camera, HDCamera ���� Ŭ�����̸�)�� ����ϴ°�"
// => People::use_camera(HDCamera*)
// => ��ü �Ұ����� ������ ������


// ���� ����(loosely coupling)
// => People �� ī�޶� ����, "��ü���� ��ǰ�̸�(Camera, HDCamera ���� Ŭ�����̸�)"
//    �� �ƴ� "��Ģ(�������̽�)�� �̸�(ICamera)" �� ����ϴ� ��
// 
// => People::use_camera(ICamera*)
// => ��ü ������ ������ ������ - ���� ����!!!
// 
// => �׷���.. ������!! => �����Լ��� ����ϰ� �ǹǷ� ������.!!
//    C++�� �پ��� ��ũ���� ����ؼ� �ذ��ϱ� ���� ���!! - ���Ϻ��� ����




