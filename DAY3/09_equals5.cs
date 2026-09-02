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

        // 단, Point 같은 사용자가 만드는 타입이 아닌
        // int, double, string 은 이미 사용자가 사용하기 쉽게 설계 되어 있음
        // == 비교하시면 됩니다.
        string s1 = "aaa";
        string s2 = "aaa";

        if (s1 == s2) { }
        // 원래 == 는 "객체 동일 조사"
        // 그런데 string 타입 설계자가 == 연산자를 재정의 해서 "상태조사"로 변경
        // 그래서 우리는 위 처럼 사용하면 동일 문자열인가 조사..


    }


}

