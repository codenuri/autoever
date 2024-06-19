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

// Download 된 그림에 다양한 꾸미는 그림(이모티콘등)을 추가하는 기능이 필요하다.

// 상속을 사용한 기능의 추가

class Frame : public Picture
{
public:
	Frame(const std::string& url) : Picture(url) {}

	void draw()
	{
		std::cout << "#######################\n";	// 추가된 기능
		Picture::draw();							// 기존 기능
		std::cout << "#######################\n";
	}
};


int main()
{
	Picture pic("www.image.com/car.jpg");
	pic.draw();
}

