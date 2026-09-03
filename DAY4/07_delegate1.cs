using System;
using static System.Console;


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
