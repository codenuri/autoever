using System;
using System.Collections.Generic;
using System.Linq;

// LINQ

static class MyLinq
{
    public static int MyWhere(   )
    {
        return 0;
    }
}




class Program
{
    public static void Main()
    {
        int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

//      var c = arr.Where(n => n % 2 == 1); 
        var c = arr.MyWhere(n => n % 2 == 1);

        foreach (var n in c)
        {
            Console.WriteLine(n);
        }
    }
}

