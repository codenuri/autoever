//this1.cs 

class Point
{
    private int x = 0;
    private int y = 0;

    public void Set(int a, int b)
    {
        x = a;
        y = b;
    }
}
class Program
{
    public static void Main()
    {
        Point p1 = new Point();
        Point p2 = new Point();

        p1.Set(1, 2);
        p2.Set(1, 2);
    }
}
