// main ���� Point �� ���� ����ϴ� ����
// => ��, ������(�߻���)�� ���� ���
// => A �κ��� �߰��Ǹ� ��� �ҽ� ������ �ٽ� ������ �Ǿ�� �Ѵ�.
// => �������� update �� �ɼ� ����.
// 
// Point.h
class Point
{
	int x, y;
	int debug; // A. ���߿� �߰�
public:
	void print();
};

// Point.cpp
#include "Point.h"

void Point::print() { } // ���� ����



// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


