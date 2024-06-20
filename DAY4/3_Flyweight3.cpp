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
		
	
	friend class ImageFactory;
};

// "Image" 클래스는 그림의 다운로드와 그리기 기능만 제공하고
// "Image" 의 생성 및 공유는 다른 클래스로 제공..
#include "helper.h"

class ImageFactory
{
	MAKE_SINGLETON(ImageFactory)

	std::map<std::string, Image*> image_map;

public:
	Image* Create(const std::string& url)
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
			img = p->second;
		}
		return img;
	}
};


int main()
{
	// Image 객체가 필요하면 "공장을 만들고, 공장을 통해서 객체를 생성" 합니다
//	ImageFactory factory;

	ImageFactory& factory = ImageFactory::get_instance();

	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();

}



