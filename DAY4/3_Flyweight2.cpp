#include <iostream>
#include <string>
#include <map>


class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	
	// inline static  : C++17 ���� �߰��� ����
	//					static ��� ����Ÿ ����, Ŭ���� �ܺ� ���� ��� �˴ϴ�.
	//					visual studio ���� C++ ���� "C++17�̻�"���� �����ؾ��մϴ�.
	inline static std::map<std::string, Image*> image_map;

	// Image ��ü�� �����ؼ� ��ȯ�ϴ� static ��� �Լ�
	static Image* Create(const std::string& url)
	{
		Image* img = nullptr;

		auto p = image_map.find(url);

		if (p == image_map.end())
		{
			img = new Image(url);
			image_map[url] = img;
		}
		else
		{
			img = p->second; // map �� ������ ��ü�� �ּ�
		}
		return img;
	}
};

int main()
{
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

}


