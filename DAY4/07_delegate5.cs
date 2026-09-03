
// delegate 를 만들때도 의미 있는 타입이름이 좋습니다.
// Predicate : 인자로 받은 타입이 조건을 만족하는지 조사할때 사용하는 함수를
//             부르는 용어
// delegate bool MyType(int n);
// delegate bool Predicate<T>(T n);  //<== 이미 C# 표준에 있습니다.

// delegate 는 언제 사용하나요 
// 1. GUI 의 event 처리 - 버튼 누를때 이벤트 처리
// 2. 메소드 인자로 다시 메소드(함수)를 받고 싶을때 
//    => Array.FindIndex() 같은 경우

// delegate 사용자가 만들어 사용하기도 하고
// 미리 만들어진 것도 있습니다.



class Program
{
    public static int MyFindIndex(int[] arr, Predicate<int> f)
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