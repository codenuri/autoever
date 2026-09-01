using static System.Console;

// 프로그램에서 Rect 타입을 많이 사용한다.

// 1. Rect 타입을 직접 만들어서 사용해도 되고

// 2. C# 언어에서 자주 사용되는 타입은 이미 "class 문법"으로 만들어서 제공
// => 기본 클래스 라이브러리(Base Class Library) 라고 표현하고
// => 10000개 이상의 타입이 제공됩니다.
// => "Rectagle, Point" 도 있습니다.

class Program
{
    public static void Main()
    {
        //        Rect rc = new Rect();
        Rectangle rc = new Rectangle(0, 0, 10, 10); // C# 표준이
                                                    // 제공하는 타입

        // 단, Rectagle 에는 "GetArea()" 메소드는 없습니다.
//        int area = rc.GetArea();
//        Console.WriteLine("면적 : {0}", area); // 0
    }
}