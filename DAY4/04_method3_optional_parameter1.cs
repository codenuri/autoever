using static System.Console;

class Example
{
    // Optional argument
    // => 인자를 전달하지 않으면 사용할 기본값을 지정하는 문법
    // => [주의] 마지막 인자 부터 차례대로만 가능
//  public void M1(int a = 0, int b,     int c = 0) // error
//  public void M1(int a = 0, int b = 0, int c = 0) // ok
    public void M1(int a,     int b = 0, int c = 0) // ok
    {
    }
}
class Program
{
    public static void Main()
    {
        Example e = new Example();

        e.M1(1, 2, 3);
        e.M1(1, 2);
        e.M1(1);
    }
}
// C++, C#, Python : 위 문법 지원
// Java, Rust      : 지원 안함