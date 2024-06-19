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
		std::this_thread::sleep_for(3s); // 3초 대기 
		std::cout << "end downding..." << std::endl;
	}

	void draw()
	{
		std::cout << "draw " << url << std::endl;
	}
};

//------------------------------------------

// 기능 추가 클래스(Decorator) 들은 공통의 특징을 가지는 경우가 많습니다.
// 이 경우 기반 클래스로 만들어서 제공하면 편리합니다.

class Decorator : public IDraw
{
	int x, y;	// 모든 기능 추가 클래스들의 
	IDraw* pic;	// 공통된 특징들을 여기서 제공
public:
	Decorator(IDraw* p) : pic(p) {}

	void draw() { pic->draw(); }
};

// 이제 모든 기능 추가 클래스는 "Decorator" 로부터 상속 받게 됩니다.
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

