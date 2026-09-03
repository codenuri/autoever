
delegate bool MyType(int n);

class Program
{
    public static int MyFindIndex(int[] arr, MyType f)
    {
        for (int idx = 0; idx < arr.Length; idx++)
        {
            // 모든 요소를 차례대로 2번째 인자로 받은 함수 에 전달해서
            // true 를 반환하는 것을 찾습니다.
            if ( f(arr[idx]) == true )            
                return idx;
        }
        return -1;
    }

    public static void Main()
    {
        int[] x = { 1, 2, 6, 8, 5 };

        // Array.FindIndex() 를 직접 구현해 봅시다
//      int ret2 = Array.FindIndex(x, Foo);

        int ret2 = MyFindIndex(x, Foo);

        Console.WriteLine("{0}", ret2);
    }

    public static bool Foo(int n) { return n % 3 == 0; }

}