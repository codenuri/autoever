using System;
using static System.Console;


class Point
{
    public int X { set; get; } = 0;
    public int Y { set; get; } = 0;
    public Point(int x, int y) => (X, Y) = (x, y);
}


class Program
{
    // "where T : 조건"     
    // => generic constrant 문법
    // => 조건만 만족하는 타입만 사용 가능하다
    // => 메소드 안에서 "조건" 이 제공하는 기능 사용가능
    public static T Max<T>(T a, T b) where T : IComparable 
    {
        return a.CompareTo(b);
    }


    public static void Main()
    {
        WriteLine($"{Max(10, 20)}");
        WriteLine($"{Max("AAA", "CC")}");

        Foo(10, 20);
    }
    public static void Foo<T>(T a, T b)
    {

    }
}
