using static System.Console;


class Car
{
    private int speed = 0;
    private static int cnt = 0;

    // 다음 코드에서 컴파일 에러를 모두 찾으세요
    public void foo()
    {
        speed = 0;  // 1
        cnt = 0;    // 2
        goo();      // 3
    }
    public static void goo();
    {
        speed = 0;  // 4
        cnt = 0;    // 5
        foo();      // 6
    }
}

class Program
{
    public static void Main()
    {

    }
}