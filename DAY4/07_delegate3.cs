using System;
using static System.Console;


delegate void MyType(int arg);

class Program
{
    public static void Main()
    {
        MyType f = Foo; 

        // #1. delegate 에 보관된 메소드 호출하는 법
        f(10);          // 1. () 연산자 사용
        f.Invoke(10);   // 2. invoke() 메소드 사용

        // #2. =, +=, -= 등으로 여러개 함수도 등록 가능
        // => 단, signature( 메소드 반환타입, 인자 모양)이 동일한 메소드만 등록가능
        MyType f1 = Foo;
        f1 += Goo;
        f1 += Hoo;

        f1(0); // 등록된 3개의 메소드 호출
    }

    public static void Foo(int arg) { WriteLine($"Foo : {arg}"); }
    public static void Goo(int arg) { WriteLine($"Goo : {arg}"); }
    public static void Hoo(int arg) { WriteLine($"Hoo : {arg}"); }
}
