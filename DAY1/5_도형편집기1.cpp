#include <iostream>
#include <vector>

// �Ŀ� ����Ʈ ���� ���α׷��� "��ü���� ����"�� ����� ����
// ������ ���ô�.

// 1. ��� ������ Ÿ������ �����ϸ� ���ϴ�.

// 2. ��� ������ ������ Ư¡�� ��� Ŭ������ ���� �����Ѵ�.
//    ��� Ŭ������ ������ "��� ������ �ϳ��� �����̳ʿ� ����" �Ҽ� �ִ�. - �ٽ�

class Shape
{
	int color;
public:
	virtual ~Shape() {}  // ���� �Ҹ���. 
};


class Rect : public Shape
{
//	int x, y, w, h;  int color, �����ڵ��� ����
public:
	void draw() { std::cout << "draw Rect\n"; }
};
class Circle : public Shape
{	
public:
	void draw() { std::cout << "draw Circle\n"; }
};

int main()
{
//	std::vector<Rect*> v;	// Rect ��ü�� ���� ����. 
	std::vector<Shape*> v;	// ��� ������ �ϳ��� �����̳ʿ� ����
							// => ������ ������ ������ ��ϵȴ�.
							// => ������ ��ġ�� �κ�(z-order)���� ���� ���� ������
							//    �Ǵ��Ҽ� �ִ�.
}

