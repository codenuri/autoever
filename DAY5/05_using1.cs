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
        // File 작업을 하려면
        
        // #1. 파일 생성
        FileStream fs = new FileStream("a.txt", FileMode.Create);

        // #2. 파일에 문자열을 쓰려면 "문자열 => byte[]" 로 변경해야 합니다
        // "ABCD" => {65, 66, 67, 68}
        byte[] data = Encoding.UTF8.GetBytes("ABCD");

        // #3. byte[] 을 파일에 쓰기
        fs.Write(data, 0,               // 파일에 처음 부터
                       data.Length);    // 데이터 크기
		
    }
}
