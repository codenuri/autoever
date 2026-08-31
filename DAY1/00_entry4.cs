// 00_entry4.cpp

System.Console.WriteLine("hello, C#");

// Top Level 방식의 한계
// => C# 에서 지원하는 일부 문법이 Top Level 에서는 에러

// C# 은 동일이름의 함수를 여러개 만들수 있지만
// Top Level 방식에서는 에러 

int square(int a)       { return a; }
double square(double a) { return a; }

// 에러의 원인
// => 위 코드는 결국 컴파일러에 의해 아래 처럼 변하는데
// => 함수 안에 만드는 함수는 이름이 동일하면 안된다 라는 문법 존재
/*
class CompilerGeneratedName   // <- 컴파일러가 임의의 이름을 사용
{
    public static void Main()
    {
        int square(int a) { return a; }
        double square(double a) { return a; }
    }
}
*/
// 결론 
// 1. Top Level 방식은 간단한 테스트 용으로만 사용하세요
// 2. 실전 개발은 Main 메소드를 만드는 방식으로 하세요

// 강의
// 1. 간단한 문법 설명은 Top Level 방식
// 2. class 문법 이후 복잡한 설명은 Main 메소드 방식 사용




