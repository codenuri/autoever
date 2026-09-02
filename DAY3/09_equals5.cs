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

        // 핵심 #1. 동일한 객체이지 조사하고 싶다
        bool ret1 = object.ReferenceEquals(p1, p2); // 최선의 코드
        bool ret2 = p1 == p2;   // 일반적으로 사용가능
                                // Point 타입이 == 를 다시 만들었다면
                                // 동일 객체라는 보장 없음

        // 핵심 #2. 상태가 동일한지 조사
        // => object 에서 물려받은 Equals 가상함수를 override 한 타입만 조사 가능

        bool ret3 = object.Equals(p3, p4); // 최선의 코드
                                            // p3 == p4 조사후 false 라면
                                            // p3.Equals(p4)
        bool ret4 = p3.Equals(p4); // 가능하지만 최선은 아님


    }


}

