using System;
using static System.Console;


// delegate
// => 함수(메소드)의 호출 정보를 보관하는 타입

// 만드는 법 알아 두세요
// 1. 함수(메소드) 선언만 복사
// 2. 반환 타입 앞에 delegate 표기
// 3. 함수(메소드) 이름 대신 원하는 타입 이름 표기
// void Foo(int arg)

delegate void MyType(int arg);

class Program
{
    public static void Main()
    {
        // ? 채워 보세요 - var 말고 정확한 타입으로
        int    n = 3;
        string s = "ABCD";

        MyType f = Foo;
        f(10); // Foo(10) 과 동일            
    }
    public static void Foo(int arg)
    {
        WriteLine($"Foo : {arg}");
    }
}
