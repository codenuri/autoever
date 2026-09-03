using static System.Console;

class MyMath
{
    // ref int ret : 메소드 안에서 ret 를 R/W 모두 하겠다는 의도
    //               Main 에서 전달시 초기화 된 변수만 전달 가능

    // out int ret : 메소드 안에서는 ret 에 쓰기만 하겠다(담아주겠다)
    //               Main 에서 전달시 초기화 되지 않은 변수도 전달가능

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
//     int ret2 = MyMath.AddSub(5, 3, ref ret1);  // error


        // 함수에서 사용할 값을 전달 : in parameter
        // 함수에 값을 꺼내오기 위해 변수 전달 : out parametrr
        // 함수에서 값을 사용하고 다시 담아주기도 하는 것 : in/out parameter

        int ret2 = MyMath.AddSub(5, 3, out ret1);  // ok

        WriteLine($"{ret1}, {ret2}");
    }
}