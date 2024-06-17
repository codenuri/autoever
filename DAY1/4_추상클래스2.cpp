//1_�߻�Ŭ����2.cpp
#include <iostream>


class Camera
{
public:	
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void use_camera(Camera* p) { p->take(); }
	void use_camera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ??
}

// OCP �̷�
// ��� Ȯ�忡 ���� �ְ�(Open, ���ο� ���/Ŭ���� �� �߰��Ǿ)
// �ڵ� �������� ���� �־��(Close, ���� �ڵ�� �������� �ʵ���)
// ������ �Ѵٴ� �̷�(Principle)

// Open Close Principle (���� ����� ��Ģ)

// ��ü ���� ����� ���Ѿ� �ϴ� 5�� ��Ģ(Principle)
// => SRP, OCP, LSP, ISP, DIP
// => ���ڷ� "SOLID" ��� �մϴ�.





