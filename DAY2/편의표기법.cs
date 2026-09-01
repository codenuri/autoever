using System.Drawing;

// 편의표기법.cs

// 규칙 #1. C# 에서 모든 종류의 객체(변수) 을 만들때는 new 를 사용합니다.

int    n = new int();
double d = new double();
string s = new string("ABC");

Rectangle r = new Rectangle(0, 0, 5, 5);

// 규칙 #2. 일부 표준 타입에 대해서, 다른 언어와 유사하게 간략히 사용할수 있도록
//          "편의 표기법" 을 제공합니다.
int    n1 = 0;  // int n1 = new int() 와 동일
double d1 = 0.0;
string s2 = "ABC";

// Rectange 은 컴파일러가 인식하는 타입(표준 타입)이 아닌 
// class 문법으로 만든 타입 
// => 편의 표기법 안됨. 반드시 new 필요

