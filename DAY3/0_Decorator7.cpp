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

	
	// ���Ͽ� ���� ��ȣȭ �ؼ� ���� ����� �ʿ� �մϴ�.
	// ��� �����ϴ� ���� �ּ��ϱ�� ?? �پ��� ����� ������ ���ô�.

	// ��� #1. FileStream Ŭ������ �����ؼ� "��ȣȭ ���" �� �߰�����.
	// => OCP ����, ����� �䱸�ɶ����� ���� Ŭ������ �����Ҽ��� ����.
	
	// ��� #2. ���. FileStream �� �Ļ� Ŭ���� "EncrpytFileStream" �� ������
	// ���� #1: FileStream �Ӿƴ϶� NetworkStream, PipeStream �� �Ļ� Ŭ���� �ʿ�
	// ���� #2: ��ȣȭ �ܿ� ���� ��ɵ� �ʿ��ϰ�, 2���� ����� ���ÿ� �����ϴ°͵� �ʿ�
	//          �ϴٸ�, �Ļ� Ŭ������ �Ļ�Ŭ����(���߻��)�ʿ�


	// ��� #3. Decorator ������ ����ϸ� ��� ?

	FileStream fs("a.txt");
	fs.write("data");

	EncryptDecorator ed(&fs);
	ed.write("data");	// 1. ed�� ����Ÿ�� ��ȣȭ�ϴ� ����� ���� ������
						// 2. fs.write() ��� ����

	ZipDecorator zd(&ed); 
	zd.write("data");	// 1. zd�� ������ ����
						// 2. ed.write(����ȵ���Ÿ) �Ӵ� ����
}