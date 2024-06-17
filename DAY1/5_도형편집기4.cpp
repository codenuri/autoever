#include <iostream>
#include <vector>

// Shape3.cpp : ���� ���� ������
// Shape4.cpp : ���� ������


// �ٽ� #1. ��� �Ļ� Ŭ������ ������ Ư¡��
//          �ݵ�� ��� Ŭ���� ���� �־�� �մϴ�.
//			�������� ������ �ƴ� "������ ����"����!!
//			Shape ���� draw() �� �־�� �մϴ�.

// �ٽ� #2. ��� Ŭ���� �Լ��� �Ļ� Ŭ������ override �ϰ� �Ǵ� ����
//			�ݵ�� "virtual"�� �ؾ� �Ѵ�.


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	// �Ʒ� �Լ��� virtual �� �ұ��? non-virtual ?
	// => �Ļ�Ŭ������ override �� ������ ����. 
	// => non-virtual
	// => virtual �� �ص� �Ǳ�������, �ʿ� ���� ���� virtual ���ϸ�
	//    "overhead" �� �ֽ��ϴ�.
	void set_color(int c) { color = c; }

	// virtual ? non-virtual
	// => ������ ���ϴ� ����� �������� �ٸ��ϴ�.
	// => �� ������ override �ϰ� �˴ϴ�.
	// => virtual !!!
	virtual int get_area() const { return 0; }


	virtual void draw() { std::cout << "draw Shape\n"; }
};




class Rect : public Shape
{
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
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;

		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)	
				p->draw();		
		}
	}
}
