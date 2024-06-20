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

	
	// inline static  : C++17 에서 추가된 문법
	//					static 멤버 데이타 사용시, 클래스 외부 선언 없어도 됩니다.
	//					visual studio 에서 C++ 버전 "C++17이상"으로 설정해야합니다.
	inline static std::map<std::string, Image*> image_map;

	// Image 객체를 생성해서 반환하는 static 멤버 함수
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
			img = p->second; // map 에 보관된 객체의 주소
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



