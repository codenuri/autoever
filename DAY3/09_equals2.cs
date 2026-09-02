using static System.Console;

/*
class object
{
    public virtual bool Equals(object other)
    { 
        // 기반 클래스인 object 를 만들때는 Point 같은 파생 클래스
        // 정보를 알수 없습니다.
        // 그래서 그냥 기본 구현은 == 로 비교 합니다.

        // 기본 구현은 == 로 자신과 인자를 비교
        return this == other;
    }
}
*/

class Point
{
    private int x = 0;
    private int y = 0;
    public Point(int a, int b) => (x, y) = (a, b);

    // Equals 를 override 해서 상태의 동일 비교로 변경
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

        // 동일성을 조사하는 방법 #1. == 연산자
        // => 객체의 동일성을 조사하는 코드
        Console.WriteLine("{0}", p1 == p2); // True
        Console.WriteLine("{0}", p3 == p4); // False


        // 방법 #2. object 에서 상속받은 Equals() 가상메소드
        // 1. object 기본 구현은 == 를 사용해서 구현 - 동일한 객체인지 조사
        // 2. 사용자가 override 해서 동일한 상태인가로 변경하는 경우가 많음
        Console.WriteLine("{0}", p1.Equals(p2));    // True
        Console.WriteLine("{0}", p3.Equals(p4));    // True
    }
}

// 핵심
// => C# 에서는 아래 2개를 모두 제공하고 싶었다
// 1. "객체 자체의 동일성" 비교 - == 제공
// 2. "상태의 동일성" 비교
// => Point 같은 클래스의 상태가 동일한가를 판단하는 기준은 Point 설계자만 알수있다
// => 그래서 Equals() 라는 가상함수를 object 클래스에 제공하고
// => Point 클래스 설계자가 override 해서 자신만의 정책으로 상태의 동질성을 판단해라!

// 결론
// Equals() override 하지 않으면 : == 와 동일한 규칙
// 보통 타입설계자가 override 해서 상태의 동일 조사로 변경하는 경우가 많음