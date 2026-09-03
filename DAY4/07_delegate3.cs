using System;
using static System.Console;


delegate void MyType(int arg);

class Program
{
    public static void Main()
    {
        MyType f = Foo; 

        // delegate 에 보관된 메소드 호출하는 법
        f(10);          // 1. () 연산자 사용
        f.Invoke(10);   // 2. invoke() 메소드 사용
    }



    public static void Foo(int arg)
    {
        WriteLine($"Foo : {arg}");
    }
}
