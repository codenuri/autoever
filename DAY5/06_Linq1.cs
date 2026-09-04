using System;
using System.Collections.Generic;
using System.Linq;

// LINQ

class Program
{
    public static void Main()
    {
        int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        // 홀수를 출력하는 방법
        // 방법 #1. 열거하면서 직접 조건을 조사
        foreach( var n in arr )
        {
            if ( n % 2 == 1)
                Console.WriteLine(n);
        }

        // 2. Linq 사용
        var c = arr.Where(n => n % 2 == 1); // () 안의 표기법은 람다표현식

        foreach( var n in c )
        {
            Console.WriteLine(n);
        }
    }
}
