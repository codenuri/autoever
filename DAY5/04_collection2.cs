using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using static System.Console;

// 핵심 : 다양한 종류의 Collection 이 있다

class Program
{
    public static void Main()
    {
        // List : 동적 배열. 모든 요소를 연속된 메모리에 보관
        //                   모든 요소에 대한 순차 접근이 빠르다.
        //                   중간에 삽입/삭제가 느리다.

        // LinkedList : 모든 요소를 떨어진 메모리 형태로 보관
        //                  모든 요소에 대한 순차 접근이 느리다
        //                   중간에 삽입/삭제가 빠르다.

        // 잘 모른다면 "List" 사용
        // => 연속된 메모리가 캐쉬 적중률이 좋습니다
        // => CPU 의 캐쉬에 여러 요소가 놓일 확률이 높다는 것

        // 이런 내용을 알고싶으면 "자료구조" 을 학습하세요

        List<int>       c1 = new List<int>();
        LinkedList<int> c2 = new LinkedList<int>();

        for (int i = 0; i < 10; i++)
        {
            c1.Add(i);      // List 는 Add 메소드
            c2.AddLast(i);  // LinkedList 는 AddLast 메소드
        }
    }
}