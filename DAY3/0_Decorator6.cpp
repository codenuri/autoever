#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// FileStream, NetworkStream, PipeStream �� ��� Stream �� 
// ������ �������� ����ϱ� ���� interface ����

struct Stream
{
	virtual void write(const std::string& data) = 0;
	virtual ~Stream() {}

	// write �ܿ��� read, open, close, flush ���� �Լ��� ���⿡ ���
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
		printf("%s ����\n", buff.c_str());
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("data");

	// FileStream �� �ƴ϶� �پ��� Stream Ŭ������ �ִٰ� ������ ���ô�.

	NetworkStream ns("127.0.0.1", 4000);
	ns.write("data");

	PipeStream ps("named pipe");
	ps.write("data");
}