using System;
using System.Collections;
using System.Collections.Generic;
using static System.Console;

// Collection ( 185 ~ )
// => 여러개의 값을 보관하는 타입

// C#, Python, Java : Collection
// C++              : Container

class Program
{
    public static void Main()
    {
        // #1. 배열 
        // => 크기를 변경할수 없는 컬렉션
        // => 요소의 추가/삭제가 안됨
        // => 성능은 제일 좋다
        int[] x = { 1, 2, 3 };
        // x.Add(3); // error


        // #2. List : 크기 변경이 가능한 동적 배열
        // => Generic 으로 설계 되었으므로 "<요소의 타입>" 으로 사용
        // => 파이썬의 list 와 동일 : s = [1,2,3]
        List<int> s = new List<int>() { 1, 2, 3 };

        s.Add(4);
        s.Add(5);
        s.Remove(3); // 제거

        s[0] = 0; // 접근은 배열과 동일



    }
}

