#include <iostream>
#include <vector>


// �ٽ� #1. template method ����
// => ��� �Ļ� Ŭ������ ������ ����Ǵ� ������ ���� ��ü���� �帧�� ���� �ڵ带
//    ��� Ŭ������ ����
// => ���ؾ� �ϴ� �κи� �����Լ�ȭ �ؼ� �Ļ� Ŭ������ �����Ҽ� �ִ� ��ȸ ����.
// => ���� �θ� ���Ǵ� ������ ����.
// => ���� ���� ��� ����




class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }
	virtual int get_area() const { return 0; }

	// ���뼺�� �������� �и�
	// => ������ ���� �ڵ� ���ο� �ִ� ���ؾ� �ϴ� �ڵ�� �и��Ѵ�.
	// => ���ؾ� �ϴ� �ڵ带 ������ �����Լ��� �и��Ѵ�.

protected:
	virtual void draw_imp()
	{
		std::cout << "draw Shape\n";
	}

public:
	void draw() 
	{ 
		std::cout << "mutex lock\n";
		draw_imp();
		std::cout << "mutex unlock\n";
	}





	virtual Shape* clone() const { return new Shape(*this); }
};




class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw Rect\n"; }

	virtual Shape* clone() const { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void draw_imp() { std::cout << "draw Circle\n"; }

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

			v.push_back(v[k]->clone());	


		}
	}
}
