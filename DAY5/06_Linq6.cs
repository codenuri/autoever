using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;

// Linq 선수지식 #3. extension method
// => 기존 클래스에 사용자가 메소드를 추가하는 문법

static class AAA    // 이름은 아무 이름이나 상관없음
{
    public static void Foo(this string s, int i)
    {
        Console.WriteLine("Foo 호출");
    }
}
class Program
{
    public static void Main()
    {
        string s = "hello";

        s.Foo(5);   // string에 Foo 가 없다면
                    // 모든 static 클래스를 조사해서
                    // Foo(this string, int) 를 조사 한다
                    // 있다면
                    // Foo(s, 5) 로 호출
    }
}
