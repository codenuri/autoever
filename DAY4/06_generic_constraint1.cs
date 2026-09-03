using System;
using static System.Console;


class Point
{
	public int X{set;get;} = 0;
	public int Y{set;get;} = 0;
	public Point(int x, int y) => (X, Y) = (x, y);
}


class Program
{
    public static T Max<T>(T a, T b) 
    {

        var ret1 = a.CompareTo(b); // error
                                   // 임의 타입에 대해서 CompareTo() 메소드가 
                                   // 있다는 보장이 없다.

        var ret2 = a.ToString();    // ok
                                    // ToSTring() 은 object 가 제공
                                    // 거의 모든 타입은 object 로 부터 파생
        // 핵심 : Generic 메소드 안에서는 기본적으로
        //       "object" 로 할수 있는 것만 사용가능
        //       다른 작업을 하려면 generic constraint 문법 사용
        // => 해결은 다음 소스
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
