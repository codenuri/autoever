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
	a.foo(); // �̷��� ����ϴ� ��쿡�� "template �ν��Ͻ�ȭ�� ���Ե˴ϴ�."
}
// ������ �ν��Ͻ�ȭ
// "class template => ���� class" �� �����Ҷ�
// ���� ����� �ν��Ͻ�ȭ�� ���Ե˴ϴ�.
// �� �ڵ忡�� "a.foo()" �� ���ٸ� "���� ������ class" �� "foo"�� ���Ծȵ˴ϴ�


