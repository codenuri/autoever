using static System.Console;

class MyMath
{
//  public static int AddSub(int a, int b, ref int ret)
    public static int AddSub(int a, int b, out int ret)
    {
        ret = a - b;
        return a + b;
    }
}

class Program
{

    public static void Main()
    {
        int ret1; // 핵심 초기값 없음
 //     int ret2 = AddSub(5, 3, ref ret1);  // error

        int ret2 = AddSub(5, 3, out ret1);  // ok

        WriteLine($"{ret1}, {ret2}");
    }
}