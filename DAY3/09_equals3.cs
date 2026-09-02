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
}

class Program
{
    public static void Main()
    {
        Point p1 = new Point(1, 2);
        Point p2 = p1;

        Point p3 = new Point(1, 2);
        Point p4 = new Point(1, 2);

        // p3 와 p4 의 상태가 동일한지 판단하는 최선의 코드를 만드세요

        bool ret; // <= 결과를 여기에 담으세요



        Console.WriteLine("{}", ret);
    }
}

