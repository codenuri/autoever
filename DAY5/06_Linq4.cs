using System;
using System.Collections.Generic;
using System.Linq;

// Linq 선수 지식 #1. foreach 원리

class Program
{
    public static void Main()
    {
        int[] arr = { 1, 2, 3 };

        foreach (int i in arr)
        {
            int n = i;  
        }
        // 위 코드는 컴파일러에 의해서 아래 코드로 변경됩니다.
        var e = arr.GetEnumerator();

        while( e.MoveNext() )
        {
            int n = e.Current;
        }
    }
}

// C# foreach, Python for, C++ ranged-for
// > 모두 원리는 반복자꺼내서 열거하는 것
