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

// ��� : Ŭ������ ��� �߰�
// ������ ����ϸ� ��ü�� ��� �߰��� �Ҽ� �ִ�.

class Frame 
{
	Picture* pic;	// �ٽ� : �����ͳ� ���� Ÿ������ ����� ����(�� Ÿ�� �ȵ�)
					// �ǵ� : �ܺο� �̹� ������ ��ü�� ����Ű�ڴٴ� ��
				
public:
	Frame(Picture* p) : pic(p) {}

	void draw()
	{
		std::cout << "#######################\n";	
		pic->draw();								// �̹� �����ϴ� ��ü�� ��� ���						
		std::cout << "#######################\n";	// �߰��� ���
	}
};


int main()
{
	Picture pic("www.image.com/car.jpg");
	pic.draw();

	Frame frame(&pic); // frame : pic ��ü�� ����� �߰��ϴ� ��ü(decorator)
	frame.draw();	   // �̼��� "pic ��� + �߰��� ���" ����		

}

