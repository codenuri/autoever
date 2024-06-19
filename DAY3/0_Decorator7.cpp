#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


struct Stream
{
	virtual void write(const std::string& data) = 0;
	virtual ~Stream() {}
};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void write(const std::string& buff)
	{
		printf("%s 쓰기\n", buff.c_str());
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("data");
	
	// 파일에 쓸때 암호화 해서 쓰는 기능이 필요 합니다.
	// 어떻게 설계하는 것이 최선일까요 ?? 다양한 방법을 생각해 봅시다.

	// 방법 #1. 상속. FileStream 의 파생 클래스 "EncrpytFileStream" 을만들자
}