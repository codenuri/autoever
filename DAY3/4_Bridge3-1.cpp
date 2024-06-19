// === ���� ������ ���� Ŭ���� ===
// => Point �� ��� ����� ���⼭ �����մϴ�.
// PointImpl.h
class PointImpl
{
	int x, y;
	int debug; 
public:
	void print();
};

// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { }




// ==== �߻��� ===
// => ����ڴ� �� Ŭ������ ����մϴ�.
// => ���� ��� ������ �����ϴ�.
// => PointImp �� ����� ����մϴ�.
// 
// Point.h
//#include "PointImpl.h"
class PointImpl; // �ٽ� : ���漱�� ������
				 //        ����� ���, ������ ������ ���𰡴�
class Point
{
	PointImpl* impl;
public:
	Point();
	void print();
};


// Point.cpp
#include "Point.h"
#include "PointImpl.h" // ���⼭�� ��� �ʿ�
						// "new PointImpl" �ϱ� ���ؼ�
Point::Point() { impl = new PointImpl; }
void Point::print() { impl->print(); }





// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


