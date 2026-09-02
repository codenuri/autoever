using static System.Console;

class Point
{
    private int x = 0;
    private int y = 0;
    public Point(int a, int b) => (x, y) = (a, b);
}

class Program
{
    public static void Main()
    {
        Point p1 = new Point(1, 2);
        Point p2 = p1;

        Point p3 = new Point(1, 2);
        Point p4 = new Point(1, 2);

        // 동일성을 조사하는 방법 #1. == 연산자

        // 결과 확인해서 == 의 기능은 "객체의 동일" 조사인지 "상태의 동일" 조사인지
        // 확인해 보세요
        Console.WriteLine("{0}", p1 == p2);
        Console.WriteLine("{0}", p3 == p4);
    }
}
