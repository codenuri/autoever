#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

struct IDraw
{
	virtual void draw() = 0;
	virtual ~IDraw() {}
};

class Picture : public IDraw
{
	std::string url;
public:
	Picture(const std::string& url) : url(url)
	{
		std::cout << "start downding..." << std::endl;
		std::this_thread::sleep_for(3s); // 3�� ��� 
		std::cout << "end downding..." << std::endl;
	}

	void draw()
	{
		std::cout << "draw " << url << std::endl;
	}
};

//------------------------------------------

// ��� �߰� Ŭ����(Decorator) ���� ������ Ư¡�� ������ ��찡 �����ϴ�.
// �� ��� ��� Ŭ������ ���� �����ϸ� ���մϴ�.

class Decorator : public IDraw
{
	int x, y;	// ��� ��� �߰� Ŭ�������� 
	IDraw* pic;	// ����� Ư¡���� ���⼭ ����
public:
	Decorator(IDraw* p) : pic(p) {}

	void draw() { pic->draw(); }
};

// ���� ��� ��� �߰� Ŭ������ "Decorator" �κ��� ��� �ް� �˴ϴ�.
class Frame : public Decorator
{
public:
	Frame(IDraw* p) : Decorator(p) {}

	void draw()
	{
		std::cout << "#######################\n";
		Decorator::draw();
		std::cout << "#######################\n";
	}
};
class Flower : public Decorator
{
public:
	Flower(IDraw* p) : Decorator(p) {}

	void draw()
	{
		std::cout << "%%%%%%%%%%%%%%%%%%%%%%%\n";
		Decorator::draw();
		std::cout << "%%%%%%%%%%%%%%%%%%%%%%%\n";
	}
};

int main()
{
	Picture pic("www.image.com/car.jpg");
	pic.draw();

	Frame frame(&pic);
	frame.draw();

	Flower flower(&frame);
	flower.draw();
}

