using System;

// 핵심 : 메소드 개념

// #1. 모든 변수는 "값" 을 보관 합니다.
int n1 = 10;        // 값 "10"    보관
string s1 = "hello";// 값 "hello" 보관

// #2. 모든 변수는 자신이 보관하는 "값" 을 사용해서 연산을 수행하는 
//     메소드를 제공합니다.
//     변수가 제공하는 함수는 "메소드" 라고 합니다.
string s = n1.ToString();
bool b = s1.Contains('a');

Console.WriteLine(b);

// 예제
string s2 = "  AAABB  "; // 앞뒤 공백 2개씩

// s2 에서 앞뒤 공백을 제거한 문자열을 얻어서 s3 에 담고 싶다
// => "s2." 한 후에 "looup table" 에서 메소드중에서 관련된 함수를 찾으세요

string s3 = s2.Trim();  // s2 자체는 변화 없고
                        // 공백이 제거된 새로운 문자열 반환
Console.WriteLine($"{s2}");
Console.WriteLine($"{s3}");


// 변수 뿐 아니라 리터럴도 메소드 사용가능(Python 도 가능)
string s4 = 10.ToString(); // ok


