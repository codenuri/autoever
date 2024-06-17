// 1_�߻�Ŭ����1.cpp - 10page

// �߻� Ŭ����(abstract class) : ���� �����Լ��� �Ѱ� �̻��ִ� Ŭ����
// Ư¡ : ��ü�� �����Ҽ� ����. ������ ������ ����� �ִ�.

// �ǵ� : ��ӵ� Ư�� �Լ��� �ݵ�� ������ �����ϴ� ��

class Shape
{
public:
	virtual void draw() = 0; // ���� �����Լ�(pure virtual function)
							 // => �����ΰ� ����, "= 0" ���� ǥ��
};
class Rect : public Shape
{
public:
	// draw() �� �����θ� �������� ������ Rect �� �߻�(abstract)
	// draw() �� �����θ� �����ϸ�        Rect �� �߻�ƴ�(concrete, ��ü)
	void draw() override {}
};
int main()
{
	Shape  s; // error.
	Shape* p; // ok
	Rect  r;  // ok
}
