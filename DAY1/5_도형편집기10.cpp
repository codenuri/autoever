#include <iostream>
#include <vector>


class NotImplemented {}; 


class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }


public:
	void draw()
	{
		std::cout << "mutex lock\n";
		draw_imp();
		std::cout << "mutex unlock\n";
	}

protected:
	virtual void draw_imp() = 0;

public:
	virtual Shape* clone() const { throw NotImplemented(); }
	virtual int get_area() const { return -1; }
};


class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Rect\n"; }

	Shape* clone() const override { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Circle\n"; }

	Shape* clone() const override { return new Circle(*this); }
};


int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;

		std::cin >> cmd;

		// �����غ� ���� #1. ��ü�� ���������� OCP �� �����ϰ� �Ҽ� ������ ?
		//                  Triangle �� �߰��Ǿ �Ʒ� �ڵ尡 ����(�߰�)���� �ʰ�
		// => �߻� ���丮(abstract factory) ������ ����ϸ� �˴ϴ� - ����ϳ� ����

		// �����غ� ���� #2. Undo/Redo �� �߰��Ϸ��� ��� �ڵ带 �ۼ��ؾ� �ұ�� ?
		// => "Command" ������ ����ϸ� �˴ϴ� - ����ϳ� ����. 

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();	// OCP ����, ���� �ڵ�
		}

		else if (cmd == 8)
		{
			std::cout << "���° ���� ������ ���� �ұ�� ?? ";
			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());	// OCP ����, ���� �ڵ�

		}
	}
}
