// �Ʒ� �ڵ�� �� ������ �ƴұ�� ?

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
