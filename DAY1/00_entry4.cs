// 00_entry4.cpp

System.Console.WriteLine("hello, C#");

// Top Level 방식의 한계
// => C# 에서 지원하는 일부 문법이 Top Level 에서는 에러

// C# 은 동일이름의 함수를 여러개 만들수 있지만
// Top Level 방식에서는 에러 

int square(int a)       { return a; }
double square(double a) { return a; }