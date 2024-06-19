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

// FileStream, NetworkStream... 등 다양한 Stream 에 기능을 추가하는
// 클래스. 모든 Stream 에 사용가능..

class EncryptDecorator : public Stream
{
	Stream* stream;		// 이미 생성된 Stream 객체를 가리키는 포인터
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	void write(const std::string& data) override
	{
		auto s2 = "[ " + data + " ] 암호화됨";	// 추가된 기능
		stream->write(s2);						// 기존 객체의 기능.
	}
};

class ZipDecorator : public Stream
{
	Stream* stream;		
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void write(const std::string& data) override
	{
		auto s2 = "[ " + data + " ] 압축됨";
		stream->write(s2);					
	}
};


int main()
{

	FileStream fs("a.txt");
	fs.write("data");

	EncryptDecorator ed(&fs);
	ed.write("data");	

	ZipDecorator zd(&ed);
	zd.write("data");	
}