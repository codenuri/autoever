class Program
{
    public static void Swap(ref int a, ref int b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    public static void Swap(ref double a, ref double b)
    {
        double tmp = a;
        a = b;
        b = tmp;
    }

    // 위 swap 는 "타입만 다르고 구현은 동일" 합니다.

    // 구현이 동일한 여러개의 메소드를 타입별로 만들어야 한다면
    // => 위처럼 직접 만들면 불편합니다(지루한 코드의 반복)
    // => 이런 경우 generic 문법 사용
    // => 해결은 다음 소스에서

    public static void Main()
    {
        int    n1 = 10,  n2 = 20;
        double d1 = 1.1, d2 = 2.3;
                
        Swap(ref n1, ref n2);
        Swap(ref d1, ref d2);
    }
}