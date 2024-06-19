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

	
	// 파일에 쓸때 암호화 해서 쓰는 기능이 필요 합니다.
	// 어떻게 설계하는 것이 최선일까요 ?? 다양한 방법을 생각해 봅시다.

	// 방법 #1. FileStream 클래스를 수정해서 "암호화 기능" 을 추가하자.
	// => OCP 위반, 기능이 요구될때마다 기존 클래스를 수정할수는 없다.
	
	// 방법 #2. 상속. FileStream 의 파생 클래스 "EncrpytFileStream" 을 만들자
	// 단점 #1: FileStream 뿐아니라 NetworkStream, PipeStream 도 파생 클래스 필요
	// 단점 #2: 암호화 외에 압축 기능도 필요하고, 2가지 기능을 동시에 제공하는것도 필요
	//          하다면, 파생 클래스의 파생클래스(다중상속)필요


	// 방법 #3. Decorator 패턴을 사용하면 어떨까 ?

	FileStream fs("a.txt");
	fs.write("data");

	EncryptDecorator ed(&fs);
	ed.write("data");	// 1. ed가 데이타를 암호화하는 기능을 먼저 수행후
						// 2. fs.write() 기능 수행

	ZipDecorator zd(&ed); 
	zd.write("data");	// 1. zd가 압축기능 수행
						// 2. ed.write(압축된데이타) ㅣ능 수행
}