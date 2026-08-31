// Top Level 방식의 원리 ( 교재 6 page )

// System.Console.WriteLine("hello, C#");


// 위 한줄을 컴파일러가 아래 처럼 수정한것
// => 컴파일러가 Main 을 만드는 것

class CompilerGeneratedName   // <- 컴파일러가 임의의 이름을 사용
{
    public static void Main()
    {
        System.Console.WriteLine("hello, C#");
    }
}
