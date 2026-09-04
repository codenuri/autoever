using System;
using System.Collections;
using System.Collections.Generic;
using static System.Console;

// 배열, List, LinkedList
// => key 만 보관(데이타만 여러개 보관)

// Dictionary - key 값을 가지고 value 를 보관하는 collection

class Program
{
    public static void Main()
    {
        Dictionary<string, string> dic = new Dictionary<string, string>();

        dic["mon"] = "월요일"; // <mon, 월요일> 의 쌍을 보관
        dic["tue"] = "화요일"; // <mon, 월요일> 의 쌍을 보관
        dic["wed"] = "수요일"; // <mon, 월요일> 의 쌍을 보관

        string s = dic["mon"]; // 월요일
        Console.WriteLine(s);
    }
}
