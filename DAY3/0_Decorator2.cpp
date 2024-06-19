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

// 상속 : 클래스에 기능 추가
// 포함을 사용하면 객체에 기능 추가를 할수 있다.

class Frame 
{
	Picture* pic;	// 핵심 : 포인터나 참조 타입으로 멤버로 포함(값 타입 안됨)
					// 의도 : 외부에 이미 생성된 객체를 가리키겠다는 것
				
public:
	Frame(Picture* p) : pic(p) {}

	void draw()
	{
		std::cout << "#######################\n";	
		pic->draw();								// 이미 존재하는 객체의 기능 사용						
		std::cout << "#######################\n";	// 추가된 기능
	}
};


int main()
{
	Picture pic("www.image.com/car.jpg");
	pic.draw();

	Frame frame(&pic); // frame : pic 객체에 기능을 추가하는 객체(decorator)
	frame.draw();	   // 이순간 "pic 기능 + 추가된 기능" 수행		

}

