#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class FileStream
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
		printf("%s ����\n", buff.c_str() );
	}
};

int main()
{
	// C��Ÿ��
	FILE* f = fopen("a.txt", "wt");
	fclose(f);

	// �� Ŭ������ �ִٸ� �Ʒ� ó�� ����ϸ� �˴ϴ�.
	FileStream fs("a.txt");
	fs.write("hello");
}