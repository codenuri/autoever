// QA1.cpp

// 아래 코드는 왜 에러인가요 ? 
// 에러가 나오는 곳과 이유를 생각해 보세요
class A
{
	int data;
public:
	void foo()
	{
		*data = 10;
	}
};

int main()
{
	A a;
}
