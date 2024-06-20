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
	a.foo(); // 이렇게 사용하는 경우에만 "template 인스턴스화에 포함됩니다."
}
// 지연된 인스턴스화
// "class template => 실제 class" 를 생성할때
// 사용된 멤버만 인스턴스화에 포함됩니다.
// 위 코드에서 "a.foo()" 가 없다면 "실제 생성된 class" 에 "foo"가 포함안됩니다


