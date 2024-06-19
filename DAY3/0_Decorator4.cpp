#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

// Picture       : Ư�� ����� �����ϴ� Ŭ����
// Frame, Flower : Picture �� ����� �߰��ϴ� Ŭ����, Decorator ����մϴ�.

// Decorator ������ �ٽ� : ��ü�� ��ø�� ��� �߰�!!!


// ����� ��� �߰��Ϸ��� Picture�� Decorator���� ������ �������̽��� �ʿ��ϴ�.

// Picture �� "draw" �� �־�� �ϰ�, 
// Picture �� ��� �߰� Ŭ����(decorator)�� "draw" �� �ʿ� �ϴ�.
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
class Frame : public IDraw
{
	IDraw* pic;
public:
	Frame(IDraw* p) : pic(p) {}

	void draw()
	{
		std::cout << "#######################\n";
		pic->draw();
		std::cout << "#######################\n";
	}
};

class Flower : public IDraw
{
	IDraw* pic;
public:
	Flower(IDraw* p) : pic(p) {}

	void draw()
	{
		std::cout << "%%%%%%%%%%%%%%%%%%%%%%%\n";
		pic->draw();
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

