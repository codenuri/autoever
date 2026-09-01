class Point
{
    private int x = 0;
    private int y = 0;

    // this 활용 #2. this 를 반환 하는 함수
    // => 자바에서 널리 사용하는 "빌더 기술"
    public Point SetX(int a)
    {
        x = a;
        return this;
    }
    public Point SetY(int a)
    {
        y = a;
        return this;
    }
}
class Program
{
    public static void Main()
    {
        Point p = new Point();
        p.SetX(3);
    }
}
