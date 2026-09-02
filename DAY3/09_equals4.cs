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

        bool ret = (p3 == p4);

        Console.WriteLine(ret);

    }
}

