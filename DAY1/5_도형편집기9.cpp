#include <iostream>
#include <vector>


class NotImplemented {}; // ���ܸ� ���� Ŭ����


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

	// �����Լ�      : �Ļ� Ŭ������ override ���� ������ �⺻ ������ �����ϰڴٴ� �ǹ�
	// ���� �����Լ� : �Ļ� Ŭ������ �ݵ�� ������ �����϶�� �����ϴ� ��. 

protected:
	virtual void draw_imp() = 0;

public:

//	virtual Shape* clone() const = 0; // �̷��� �ص� �ǰ�!! ���� �ڵ�!!

	// �Ʒ� ���� ����� ��쵵 �ֽ��ϴ�.
	// 1. override ���� �ʰ� ����ϸ� ���� �߻�
	// 2. override ���� �ʰ� ��������� ������ ok
	// 3. override �ϰ� ����ϸ� ok. 
	// => ��, ����ϴ� ��츸 override �ϸ� �ȴٴ� ��. "���̽� ��� ���� ���"

	virtual Shape* clone() const { throw NotImplemented(); }


	// �Ʒ� �ڵ嵵 "=0", "�⺻ ���� ����"�� �ص� �ǰ�
	// => ���и� ��Ÿ���� ���� ��ȯ�ϰ� �ص� �˴ϴ�.
	// => "get_area() ȣ��� -1�� ������ �������Ҽ� ����" �̶�� �Ŵ����ۼ�.
	virtual int get_area() const { return -1; }

};


class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Rect\n"; }

	Shape* clone() const override  { return new Rect(*this); }
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
