#include <iostream>
#include <vector>





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
	virtual void draw_imp()
	{
		std::cout << "draw Shape\n";
	}

public:
	virtual Shape* clone() const { return new Shape(*this); }

	virtual int get_area() const { return 0; }

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
			std::cout << "몇번째 만든 도형을 복제 할까요 ?? ";
			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());


		}
	}
}
