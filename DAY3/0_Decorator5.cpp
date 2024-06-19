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
		printf("%s 쓰기\n", buff.c_str() );
	}
};

int main()
{
	// C스타일
	FILE* f = fopen("a.txt", "wt");
	fclose(f);

	// 위 클래스가 있다면 아래 처럼 사용하면 됩니다.
	FileStream fs("a.txt");
	fs.write("hello");
}