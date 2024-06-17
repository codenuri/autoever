#include <iostream>
#include <vector>

// �����丵 : ���ο� ����� �߰��ϴ� ���� �ƴ϶�, 
//            ���� �ڵ带 ���� ������ �����ϴ� ��. 

// �ٽ� #1. �����丵���� ���Ǵ� ���� ������ ��� �Դϴ�. �ǹ̸� ������ ������

// "replace conditional with polymorphism"
// "        ���(if, switch) �� ������(�����Լ�)�� �����ض�"
// 
// Shape3.cpp �� Shape4.cpp �� �����ض�
// Shape6.cpp �� Shape7.cpp �� �����ض�



// 



class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }
	virtual int get_area() const { return 0; }
	virtual void draw() { std::cout << "draw Shape\n"; }


	// �ڽ��� ���纻�� ����� �����Լ��� �׻� �����ϰ� Ȱ�� �˴ϴ�.
	virtual Shape* clone() const { return new Shape( *this ); }
};




class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }

	virtual Shape* clone() const { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }

	virtual Shape* clone() const { return new Circle(*this); }
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

		else if (cmd == 8)
		{
			std::cout << "���° ���� ������ ���� �ұ�� ?? ";
			int k;
			std::cin >> k;

			// ��� #2. ������!!!
			// => OCP �� �����ϴ� ���� ������
			// => �������� �ᱹ "�ش� ����� �����ϴ� �����Լ�" �� ������ ��!

			v.push_back( v[k]->clone() );	// ������ Ȱ��!!
											// => k ��° ������ �������� ���ʿ����.
											// => ���ο� ������ �߰��Ǿ 
											//	  �� �ڵ�� ������ �ʿ� ����.


		}
	}
}
