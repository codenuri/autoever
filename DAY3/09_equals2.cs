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
        // => 객체의 동일성을 조사하는 코드
        Console.WriteLine("{0}", p1 == p2); // True
        Console.WriteLine("{0}", p3 == p4); // False

        // 방법 #2. object 에서 상속받은 Equals() 가상메소드
        Console.WriteLine("{0}", p1.Equals(p2));
        Console.WriteLine("{0}", p3.Equals(p4));
    }
}
