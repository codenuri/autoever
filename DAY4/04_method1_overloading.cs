using static System.Console;

// method overloading 문법
// => 동일한 이름의 메소드를 여러개 만들수 있다
// => 단, 인자의 타입 또는 갯수가 달라서 호출시 구별이 가능해야 한다

// 장점 : 실제 메소드가 여러개 라도, 사용자는 동일한 메소드 처럼 사용

// C#, C++, Java, Swift : 이 문법 지원
// C, Rust, Python      : 이 문법 지원 안함


class Math
{
    public int Square(int x)
    {
        return x * x;
    }
    public double Square(double x)
    {
        return x * x;
    }
}



class Program
{
    public static void Main()
    {
        Math m = new Math();

        var ret1 = m.Square(3);
        var ret2 = m.Square(3.3);
    }
}