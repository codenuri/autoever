using System;
using static System.Console;


delegate void MyType(int arg);

// delegate 의 원리
// => 위 코드 처럼 "문법대로 코드를 작성하면"
// => 컴파일러가 위 코드를 참고해서 class 를 생성합니다.
/*
class MyType : MulticastDelegate
{
    // 함수의 호출 정보를 보관했다가 
    // 원할때 호출하기 위한 다양한 멤버들 추가
}
*/

class Program
{
    public static void Main()
    {
        MyType f1 = new MyType(Foo); // 정확한 표기법  int n = new int()
        MyType f2 = Foo;  // 편의 표기법 제공          int n = 0

        MyType f = Foo; // 함수 구현 코드 자체를 f 가 보관하는 것이 아니라
                        // 함수 호출에 필요한 정보(함수(메소드) 주소)를 보관
        f(10);             
    }
    public static void Foo(int arg)
    {
        WriteLine($"Foo : {arg}");
    }
}
