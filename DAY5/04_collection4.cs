using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using static System.Console;

class Program
{
    public static void Main()
    {
        List<int> c1 = new List<int>();
        LinkedList<int> c2 = new LinkedList<int>();

        for (int i = 0; i < 10; i++)
        {
            c1.Add(i);
            c2.AddLast(i);
        }
        //---------------------------------------------
        // 컬렉션의 모든 요소에 접근하는 3가지 방법
        // #1. foreach 사용 
        // => 가장 권장,
        // => c1 의 위치에는 모든 컬렉션 사용가능(배열, List, LinkedList, ...)
        foreach(var e in c1 )
        {
            Console.WriteLine(e);
        }

        // #2. 반복자(열거자) 사용 
        // => 전체가 아닌 일부만 접근하고 싶을때등..
        var e1 = c1.GetEnumerator();

        // 아래 코드는 전체..
        while( e1.MoveNext())
        {
            int n = e1.Current;
        }
        // 일부만 하려면
        e1.Reset(); // 다시 처음 부터
        int n1 = e1.Current;
        e1.MoveNext();
        int n2 = e1.Current;





        // #3. for 와 [] 사용..

    }
}