#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {} 
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
}

