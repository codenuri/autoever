using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using static System.Console;

// 반복자
class Program
{
    public static void Main()
    {
        List<int>       c1 = new List<int>();
        LinkedList<int> c2 = new LinkedList<int>();

        for(int i = 0; i < 10; i++)
        {
            c1.Add(i);
            c2.AddLast(i);
        }
		// ---------------------------------------------
        // #1. [] 연산자
        // List       : [] 연산자로 요소 접근 가능
        // LinkedList : [] 연산자 사용 못함
        c1[0] = 0; // ok
//      c2[0] = 0; // error


        // 반복자(열거자)
        // => 컬렉션의 모든 요소를 순차적으로 접근할때 사용하는 도구
        // => 모든 컬렉션의 반복자(열거자)는 사용법이 동일

        var e1 = c1.GetEnumerator();    // List 의 반복자(열거자)
        var e2 = c2.GetEnumerator();    // LinkedList 의 반복자(열거자)
        
        // List 와 LinkedList 는 메모리 구조가 다릅니다.
        // => 그런데, e1, e2 를 사용하면 동일한 방식으로 열거 가능합니다
        while ( e1.MoveNext() )
        {
            Console.WriteLine("{0}", e1.Current);
        }
    }
}