using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    public static void Main()
    {
        int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        var c = arr.Where(n => n % 2 == 1);

        arr[0] = 99;

        // 아래 결과 예측해 보세요. 첫번째 출력이 "1" 일까요 ? "99" 일까요 ?
        foreach (var n in c)
        {
            Console.WriteLine(n);
        }
    }
}
