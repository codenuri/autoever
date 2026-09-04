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
        // File 작업을 하려면
        
        // #1. 파일 생성
        FileStream fs = new FileStream("a.txt", FileMode.Create);

        // #2. 파일에 문자열을 쓰려면 "문자열 => byte[]" 로 변경해야 합니다
        // "ABCD" => {65, 66, 67, 68}
        byte[] data = Encoding.UTF8.GetBytes("ABCD");

        // #3. byte[] 을 파일에 쓰기
        fs.Write(data, 0,               // 파일에 처음 부터
                       data.Length);    // 데이터 크기

//      fs.Close();	 // 옛날스타일	
        fs.Dispose();// 위와 동일, 권장
                     // => 파일이 아닌 다른 자원들이 사용하는 것과
                     //    동일한 이름을 사용하기 위해서 추가된 것
    }
}
// 프로젝트이름(DAY5)\bin\Debug\net10.0 안에 a.txt 있습니다.

// C/C++ : 자원획득하면 사용자가 직접 반환 해야 합니다.
//int* p = new int;
//delete p;

// C#/Java/Rust/Python
// => 자동으로 자원해지 됩니다.
// => 할당만 해서 사용하면 됩니다.

// C# 에서 파일 또는 네트워크 작업시
// => 파일을 닫지 않아도 "언젠가는" "자동으로 Close" 됩니다
// => {} 벗어날때 즉시 되지 않습니다.(C++ 소멸자와 다릅니다.)
// => 닫히기 전까지는 해당 자원(파일)을 다른 프로그램이 사용못합니다
// => 따라서 되도록이면 사용자가 명시적으로 닫으세요
// => 정확히 알고 싶다면 "C# Garbage Collector" 학습
