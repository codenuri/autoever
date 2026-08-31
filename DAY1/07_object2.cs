using static System.Console;

// 핵심 : 메소드와 프라퍼티
// => 프라퍼티는 C# 에만 있는 독특한 문법
// => C# 언어의 핵심중의 핵심

// 메소드   : "변수이름.이름()" 를 사용해서 호출
// 프라퍼티 : "변수이름.이름" 으로 접근 - () 없음

string s = "abcd";

bool b = s.Contains('b');
int  n = s.Length;       

WriteLine($"{b} {n}");

