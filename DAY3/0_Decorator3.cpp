// Decorator - 65 page
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

// Picture : 인터넷에서 그림을 Download 한후에 화면에 그리는 기능.
class Picture
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
class Frame
{
	Picture* pic;	
public:
	Frame(Picture* p) : pic(p) {}

	void draw()
	{
		std::cout << "#######################\n";
		pic->draw();								
		std::cout << "#######################\n";	
	}
};

class Flower
{
	Picture* pic;
public:
	Flower(Picture* p) : pic(p) {}

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

	Flower flower(&pic);
	flower.draw();
}

