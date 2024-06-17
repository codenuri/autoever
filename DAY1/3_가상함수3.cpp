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
	// => 에러가 아닙니다.
	// => 다른 가상함수를 만든 것으로 취급. 
//	virtual void fooo() {}		// 오타
//	virtual void goo(double){}

	// #3. 위 문제 때문에 C++ 진영에서 "버그"가 아주 많았습니다.
	// => 그래서, C++11 에서 "override" 키워드 추가
	virtual void fooo() override {}	 // error.	 
};

int main()
{
}





