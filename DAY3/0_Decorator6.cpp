#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// FileStream, NetworkStream, PipeStream 등 모든 Stream 의 
// 사용법이 동일함을 약속하기 위해 interface 설계

struct Stream
{
	virtual void write(const std::string& data) = 0;
	virtual ~Stream() {}

	// write 외에도 read, open, close, flush 등의 함수를 여기에 약속
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

	// FileStream 뿐 아니라 다양한 Stream 클래스가 있다고 생각해 봅시다.

	NetworkStream ns("127.0.0.1", 4000);
	ns.write("data");

	PipeStream ps("named pipe");
	ps.write("data");
}