using System;


// .Net 에서 4바이트 정수에 대한 정확한 타입은
// => Int32 타입입니다
// => int 라는 타입은 Int32 타입의 별명입니다

// 아래 2줄은 완전히 동일합니다.
int   n1 = 0;
System.Int32 n2 = 0;


// Int32 는 System 안에 있습니다.
// int 는 키워드(컴파일러가 인식하는 글자) 입니다.
System.Int32 a1 = 0; // ok
Int32 a2 = 0;        // ok

System.int a3 = 0; // error
int a4 = 0;        // ok
//-------------------------------

// C# 처음 배열때 타입이름을 어려워 합니다.
// => "double" 이 맞나요 ? "Double" 이 맞나요 ? 질문 많이 합니다
double d1 = 0;  // C# 키워드. 아래 타입의 별명
Double d2 = 0;  // CTS 에 정의 된 이름
System.Double d3 = 0;

string s1 = "A";
String s2 = "A";
System.String s3 = "A";

// 권장 : CTS 이름 말고 C# 키워드 사용하세요(모두 소문자)