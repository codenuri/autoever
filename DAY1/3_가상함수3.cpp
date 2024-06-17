// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
// 핵심 : 간단한 문법정리!!
class Derived : public Base
{
public:
	// #1. 가상 함수 override 시에는 virtual 이 있어도 되고 없어도 됩니다.
//	virtual void foo() {} // ok
//	void foo() {}		  // ok. 위와 완벽히 동일


	// #2. 가상함수 override 시에 "실수(오타)"가 있으면
	// => 
	virtual void fooo() {}		// 오타
	virtual void goo(double){}
};

int main()
{
}





