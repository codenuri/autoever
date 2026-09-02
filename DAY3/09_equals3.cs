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
        
        bool ret = p3 == p4; // 같은 객체인가 ? 같은 객체는 상태도 동일

        // 동일 객체가 아닌 경우만 상태 조사
        if (ret == false)
        {
            ret = p3.Equals(p4);
        }
        
        //-----------------------------------
        // 아래 한줄이 위코드와 동일
        // object 클래스의 "Equals" static method
        bool ret2 = object.Equals(p3, p4); // 


        Console.WriteLine("{}", ret);


    }
}

