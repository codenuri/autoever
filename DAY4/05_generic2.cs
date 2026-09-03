class Program
{
    // 아래 Swap 은 메소드가 아닌 "메소드를 만드는 틀" 입니다.
    // 사용법 : Swap<원하는 타입>(ref n1, ref n2)
    
    public static void Swap<T>(ref T a, ref T b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }



    public static void Main()
    {
        int n1 = 10, n2 = 20;
        double d1 = 1.1, d2 = 2.3;

        // Generic 을 사용하는 정확한 표기법
        Swap<int>(ref n1, ref n2);
        Swap<double>(ref d1, ref d2);
    }
}