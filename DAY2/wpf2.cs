
// C# 언어는 "class" 문법으로 만들어진 수천개의 타입을 제공합니다.
// 다양한 분야별로 제공되는데..

// 이때 GUI 를 만들기 위한 라이브러리중 가장 유명한 것이 "WPF" 입니다.
// WPF : Windows Presentation Framework

// WPF 를 사용하려면 환경설정이 필요 합니다.
// 방법 #1. 프로젝트의 종류를 "WPF 관련프로젝트" 로 선택
// => 단, 이방법 선택시 자동생성되는 코드가 너무 많습니다

// 방법 #2. 프로젝트의 종류를 "콘솔앱" 으로 선택
// => Program.cs 가 생성되지만 아주 간단한 소스
// => 이후 WPF 사용하겠다는 것은 프로젝트 파일에 직접 작성

// 설정 방법

// 변경할것 :  <TargetFramework>net10.0-windows</TargetFramework>
// 추가할것 :  <UseWPF> true </UseWPF>

using System.Windows;

class Program
{
    public static void Main()
    {
        MessageBox.Show("Hello, WPF");
    }
}