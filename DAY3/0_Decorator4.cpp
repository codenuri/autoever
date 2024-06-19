#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

// Picture       : 특정 기능을 수행하는 클래스
// Frame, Flower : Picture 에 기능을 추가하는 클래스, Decorator 라고합니다.

// Decorator 패턴의 핵심 : 객체에 중첩된 기능 추가!!!


// 기능을 계속 추가하려면 Picture와 Decorator들은 공통의 인터페이스가 필요하다.

// Picture 도 "draw" 가 있어야 하고, 
// Picture 에 기능 추가 클래스(decorator)도 "draw" 가 필요 하다.
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

