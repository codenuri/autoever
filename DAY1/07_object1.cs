using System;

// 핵심 : 메소드 개념

// #1. 모든 변수는 "값" 을 보관 합니다.
int n1 = 10;        // 값 "10"    보관
string s1 = "hello";// 값 "hello" 보관

// #2. 모든 변수는 자신이 보관하는 "값" 을 사용해서 연산을 수행하는 
//     메소드를 제공합니다.
string s = n1.ToString();
bool b = s1.Contains('a');

Console.WriteLine(b);



