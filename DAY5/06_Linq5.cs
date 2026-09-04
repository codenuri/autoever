using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;

// Linq 선수 지식 #2. coroutine
// => C# 은 coroutine 을 반복자 기반으로 설계 했습니다.

class Program
{
    // coroutine 을 만들려면
    // 1. 반환 타입은 IEnumearable<int>
    // 2. 호출자에게 돌아가고 싶을때 "yield return"
    public static IEnumerable<int> foo()
    {
        Console.WriteLine("foo #1");
        yield return 1;

        Console.WriteLine("foo #2");
        yield return 1;
    }
    public static void Main()
    {
        var ret = foo();

        var e = ret.GetEnumerator();

        e.MoveNext(); // 이순간 최초로 foo 안의 사용자 코드 실행
        Console.WriteLine("Main #1. foo 반환값 : {0}", e.Current);

        e.MoveNext(); // 이순간 최초로 foo 안의 사용자 코드 실행
        Console.WriteLine("Main #1. foo 반환값 : {0}", e.Current);
    }
}
