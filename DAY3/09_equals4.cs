using static System.Console;

class Point
{
    private int x = 0;
    private int y = 0;
    public Point(int a, int b) => (x, y) = (a, b);

    public override bool Equals(object obj)
    {
        Point other = (Point)obj;
        return x == other.x && y == other.y;
    }

    // 사용자가 == 연산자를 다시 만드는 기능이 있습니다.
    // => 아래 구현은 상태의 동일성 조사로 변경한것
    public static bool operator ==(Point a, Point b)
    {
        return a.x == b.x && a.y == b.y;
    }

    // == 만들면 != 도 만들어야 합니다.
    public static bool operator !=(Point a, Point b)
    {
        return !(a == b);
    }
}

class Program
{
    public static void Main()
    {
        Point p1 = new Point(1, 2);
        Point p2 = p1;

        Point p3 = new Point(1, 2);
        Point p4 = new Point(1, 2);

        //--------------------------------
        // 동일한 객체 인가의 조사
        // == 연산자 사용
        // 하지만 == 연산자는 재정의 가능

        // 아래 코드는 사용자가 재정의한 == 를 호출하므로 상태 조사
        bool ret = (p3 == p4);  
        Console.WriteLine(ret);

        // 해결책
        // => object 타입으로 변경해서 == 사용
        // => Point 타입이 아니므로 사용자가 만든 == 호출 안됨
        bool ret2 = ((object)p3 == (object)p4);
        Console.WriteLine(ret2);

        // p3 == p4 : p3, p4 가 Point 타입이므로 Point 가 다시만든 == 사용
        // MyReferenceEquals(p3, p4) : object 타입으로 변경해서 비교 하므로
        //                              항상 객체의 동일성 비교

        bool ret3 = MyReferenceEquals(p3, p4);
        bool ret4 = object.ReferenceEquals(p3, p4); // 이 표준함수가 위 함수와 동일
        Console.WriteLine(ret3);
    }

    // 아래 함수의 의미를 잘생각해보세요
    public static bool MyReferenceEquals(object a, object b)
    {
        return a == b;
    }
}

