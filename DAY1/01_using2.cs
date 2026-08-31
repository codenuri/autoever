// System  : Namespace 문법 ( Python 은 모듈 개념)
// Console : 클래스 이름
// WriteLine : 정적 메소드(함수)이름

//System.Console.WriteLine("C#"); 

using System;   // System 이름 공간에 있는 것은 System 없이 사용가능하게 해달라
                // 파이썬의 import 와 유사

using static System.Console; // System.Console 의 정적 메소드를 
                             // System.Console 없이 사용가능

global using System;         // 이 소스뿐 아니라 다른 소스에도 적용
global using static System.Console;

Console.WriteLine("C#");    // using System 때문에 가능

WriteLine("C#");            // using System.Console 때문에 가능