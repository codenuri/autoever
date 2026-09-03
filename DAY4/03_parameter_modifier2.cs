using static System.Console;

class MyMath
{
    public static int AddSub(int a, int b, ref int ret)
    {
        ret = a - b;
        return a + b;
    }
}

class Program
{

    public static void Main()
    {
        int ret1 = 0;

        // AddSub
        // => 5 + 3 의 결과는 반환 값으로 전달
        // => 5 - 3 의 결과는 3번째 인자로 전달한 변수에 담아달라.
        //    결과를 담아와야 하므로 ref 로 전달 한것  
        int ret2 = AddSub(5, 3, ref ret1); 

        WriteLine($"{ret1}, {ret2}"); 
    }
}