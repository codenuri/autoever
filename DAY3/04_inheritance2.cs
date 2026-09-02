// object 이야기

// C# 언어의 특징
// => 대부분의 타입은 object 라는 클래스로 부터 상속 받는다
// => ": object" 가 없어도 자동으로 상속된다
/*
// C# 내부 코드
namespace System
{
    class object
    {
        // ToString() 등의 몇개 메소드 제공
    }
}
*/

// 사용자 코드       // 컴파일러가 변경한 코드
class Car           // class Car : object
{
    // 어떠한 멤버도 없습니다.
}

class Program
{
    public static void Main()
    {
        Car c = new Car();

        string s = c.ToString();

        Console.WriteLine(s); // 결과의 의미를 ToString() 예제에서 설명
    }
}