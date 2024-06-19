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
		printf("%s ����\n", buff.c_str());
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("data");
	
	// ���Ͽ� ���� ��ȣȭ �ؼ� ���� ����� �ʿ� �մϴ�.
	// ��� �����ϴ� ���� �ּ��ϱ�� ?? �پ��� ����� ������ ���ô�.

	// ��� #1. ���. FileStream �� �Ļ� Ŭ���� "EncrpytFileStream" ��������
}