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

// FileStream, NetworkStream... �� �پ��� Stream �� ����� �߰��ϴ�
// Ŭ����. ��� Stream �� ��밡��..

class EncryptDecorator : public Stream
{
	Stream* stream;		// �̹� ������ Stream ��ü�� ����Ű�� ������
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	void write(const std::string& data) override
	{
		auto s2 = "[ " + data + " ] ��ȣȭ��";	// �߰��� ���
		stream->write(s2);						// ���� ��ü�� ���.
	}
};

class ZipDecorator : public Stream
{
	Stream* stream;		
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void write(const std::string& data) override
	{
		auto s2 = "[ " + data + " ] �����";
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

// �� ó�� ���� �ߴٸ� "Stream" ���� ����� �ʿ��Ҷ�����
// ��� �߰� Ŭ����(Decorator) �鸸 ��� ����� �˴ϴ�.
// �ϳ��� Decorator �� ��� Stream ���� ���� �����մϴ�.!!

// ���ۿ��� "C# Stream" �˻��� ������. (�̹��� ����� �غ�����)