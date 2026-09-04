using Microsoft.VisualBasic.FileIO;
using System;
using System.IO;
using System.Text;

// C# 학습
// 1. 다양한 문법을 공부 하세요(property, delegate, interface... )
// 2. 다양한 표준 라이브러리(타입)의 사용법을 알아야 합니다.
// => File 작업 : FileStream
// => 네트워크  : 수백개의 관련 클래스
// => UI : WPF 등의 라이브러리

class Program
{
    static void Main()
    {
        using ( FileStream fs = new FileStream("a.txt", FileMode.Create) )
        {
            byte[] data = Encoding.UTF8.GetBytes("ABCD");

            fs.Write(data, 0, data.Length);

            // 자원의 관리는 메소드 아래 부분에서 
            // 사용자가 직접 하는 것은 위험 합니다.
            // fs.Dispose();

        } // <- 이 블럭을 벗아 날때 fs.Dispose()가 자동으로 수행
    }
}
// 위와 같은 기술을
// C++/Rust 에서 "RAII" 라고 합니다.
// => 요즘 대부분 언어의 특징
