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
    // => generic constraint 문법
    // => 조건만 만족하는 타입만 사용 가능하다
    // => 메소드 안에서 "조건" 이 제공하는 기능 사용가능
    public static T Max<T>(T a, T b) where T : IComparable 
    {
        // 이안에서는 이제 IComparable 인터페이스가 제공하는 
        // 메소드 호출 가능
        return a.CompareTo(b);
    }

    public static void Main()
    {
        WriteLine($"{Max(10, 20)}");        // ok int 는 IComparable 구현
        WriteLine($"{Max("AAA", "CC")}");   // ok string 는 IComparable 구현


        Point p1 = new Point(1, 1);
        Point p2 = new Point(2, 2);

        WriteLine($"{Max(p1, p2)}"); // error. Point 은 IComparable 구현안함
                                    // 구현 했다면 전달 가능

    }
}
