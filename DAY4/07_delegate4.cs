class Program
{
    public static void Main()
    {
        int[] x = { 1, 2, 6, 8, 5 };

        // 배열에 대한 모든 연산은 "Array" 클래스의 정적 메소드에서 찾으세요
        // #1. 배열에서 2가 몇번째 있는지 알고 싶다
        int ret1 = Array.IndexOf(x, 2);
        Console.WriteLine("{0}", ret1); // 1

        // #2. 배열에서 처음 나오는 3의 배수를 찾고 싶다
        // int ret2 = Array.IndexOf(x, 6); // 이코드는 6을 찾는 것

        // int ret2 = Array.FindIndex(x, 함수);
        int ret2 = Array.FindIndex(x, Foo);

        Console.WriteLine("{0}", ret2);
    }

    public static bool Foo(int n) { return n % 3 == 0; }

}