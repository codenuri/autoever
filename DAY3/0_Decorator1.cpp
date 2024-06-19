// Decorator - 65 page
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

// Picture : ���ͳݿ��� �׸��� Download ���Ŀ� ȭ�鿡 �׸��� ���.
class Picture
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

// Download �� �׸��� �پ��� �ٹ̴� �׸�(�̸�Ƽ�ܵ�)�� �߰��ϴ� ����� �ʿ��ϴ�.

// ����� ����� ����� �߰�

class Frame : public Picture
{
public:
	Frame(const std::string& url) : Picture(url) {}

	void draw()
	{
		std::cout << "#######################\n";	// �߰��� ���
		Picture::draw();							// ���� ���
		std::cout << "#######################\n";
	}
};


int main()
{
	Picture pic("www.image.com/car.jpg");
	pic.draw();
}

