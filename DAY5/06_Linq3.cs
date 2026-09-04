using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    public static void Main()
    {
        string[] arr = { "kim", "park", "choi", "lee", "jung" };

        // 아래 코드의 문법 자체는 "method chaining" 기술
        // => p.foo().goo().hoo() 하고 있는 것
        // => 각 메소드가 this 를 반환

        var c = arr.Where(s => s.Contains('i'))   // "kim", "choi"
                   .OrderBy(s => s.Length)        // "kim", "choi"
                   .Select(s => s.ToUpper());      // "KIM", "CHOI" 

        // 위 코드는 아직 람다표현식이 실행되지 않은것
        // c 안에 "배열의 참조와 3개 람다 표현식" 만 보관
        // 열거할때 적용

        foreach (var n in c)
        {
            Console.WriteLine(n);
        }
    }
}

// 위 코드는 "SQL" 처럼 보입니다.
// 그래서 이 기술의 이름이 "Language INtegrated Query" 라고 해서
// LINQ 라고 합니다.

// C# LINQ     : 2007 년에 도입 - 배열뿐 아니라 대부분의 Collection 에 사용가능
// Java Stream : 2014 년에 도입 - LINQ 와 거의 동일 개념
// Rust Iterator: 2015 년 - 반복자 자체에 위와 동일 개념 제공
// C++ Views    : 2020 년 - C++20 기술의 std::views 라이브러리