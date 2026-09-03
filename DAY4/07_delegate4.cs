class Program
{
    public static void Main()
    {
        int[] x = { 1, 2, 6, 8, 5 };

        // 배열에서 2가 몇번째 있는지 알고 싶다
        // => 배열에 대한 모든 연산은 "Array" 클래스의 정적 메소드에서 찾으세요
        int ret1 = Array.IndexOf(x, 2);

        Console.WriteLine("{0}", ret1); // 1
    }

}