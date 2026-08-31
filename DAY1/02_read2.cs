// using System;

// C# 내부
/*
namespace System
{
    class Console
    {
        // 출력과 관련된 다양한 정적 메소드
        // 입력과 관련된 다양한 정적 메소드
    }
}
*/

// Console 창에 대한 모든 작업은 
// => Console 클래스에서 메소드 찾으세요
Console.Clear(); // 화면 지우기 

// 화면 출력
Console.Write("input yout name >> ");

// 사용자 입력 : ReadLine 메소드
string s = Console.ReadLine();

Console.WriteLine("입력된 이름 {0}", s);




