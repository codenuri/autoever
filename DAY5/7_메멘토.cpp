// 8_�޸��� - 178
#include <iostream>


// ȭ�鿡 �׸��� �׸��� ����ϴ� Ŭ����
class Graphics
{
	// ���鰡���� �׸��� �Լ��� �����մϴ�.
};


int main()
{
	Graphics g;
	g.DrawLine(0, 0, 100, 100);

	// ���� �����̳� �β� ���� �����ϰ� �ͽ��ϴ�.

	// ��� #1. �Լ� ���ڷ� "����, �β�" �� ��������
	// => windows �� gdi+ ���̺귯�� ���
	g.DrawLine(0, 0, 100, 100, red, 5);
	g.DrawLine(0, 0, 100, 100, red, 5);


	// ��� #2. Graphics ��ü�� �Ӽ����� "����, �β�" �� ��������.
	// => IOS �� cocoa touch ���̺귯�� ���
	g.SetStrokeColor(red);
	g.SetStrokeWidth(5);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 100, 100);
}









