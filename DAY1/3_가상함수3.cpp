// 2_�����Լ�������
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
// �ٽ� : ������ ��������!!
class Derived : public Base
{
public:
	// #1. ���� �Լ� override �ÿ��� virtual �� �־ �ǰ� ��� �˴ϴ�.
//	virtual void foo() {} // ok
//	void foo() {}		  // ok. ���� �Ϻ��� ����


	// #2. �����Լ� override �ÿ� "�Ǽ�(��Ÿ)"�� ������
	// => 
	virtual void fooo() {}		// ��Ÿ
	virtual void goo(double){}
};

int main()
{
}





