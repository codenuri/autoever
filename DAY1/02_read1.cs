// 02_read1.cs

// namespace 개념
// => 프로그램 또는 라이브러리의 요소를 논리적으로 분할해서
// => 이름 출동을 막을때 사용
namespace Audio
{
    class Card { }
}
namespace Video
{
    class Card { }
}

Audio.Card c1;
Video.Card c2;

// C# 의 모든 기본요소는 System namespace 안에 있습니다.
// C# 내부 코드 - 아래 코드는 컴파일 안됨. 설명을 위한 코드
namespace System
{
    //.. 모든 C# 기본 라이브러리들.. 
    class Console 
    {
        public static void WriteLine(string s) { ... }
    }
}

System.Console.WriteLine("aa");


