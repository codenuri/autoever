// 1. C# 언어 버전
// C# 1.0 : 2002 Release
// C# 14.0: 2025년 12월 Release. 요즘 트렌드 매년 연말에 새버전 발표
// 현업 : C#6.0 ~ C#9.0 정도.. 

// 2. 소스 파일 확장자 : .cs

// 3. entry point
// => 소스에서 제일 먼저 실행되는 부분
// => 대부분의 프로그래밍 언어의 entry point 방식
// 1. 약속된 함수에서 부터 실행 - C/C++/Rust/Java 등, 보통 main 이라는 이름의 함수
// 2. 소스 코드의 제일 처음 부터 차례대로 실행 - Python


// C# 의 경우 2가지 방식 모두 지원

// 방법 #1. 임의 이름의 사용하는 "클래스"를 만들고
//          약속된 이름은 "Main" 메소드를 만들어라. 
class Program       // <= "Program" 이름은 마음대로 수정가능
{
    public static void Main()   // <= "Main" 은 약속된 이름
    {
        System.Console.WriteLine("hello, C#");
    }
}