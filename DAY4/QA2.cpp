// 아래 코드는 왜 에러가 아닐까요 ?

template<typename T>
class A
{
	T data;
public:
	void foo()
	{
		*data = 10; 
	}
};

int main()
{
	A<int> a;
}
