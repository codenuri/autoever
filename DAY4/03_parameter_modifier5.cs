using static System.Console;

// try parse 
class Program
{
	public static void Main()
	{
        // 문자열을 정수로 변경 하는 방법

        // 방법 #1. int.Parse() 
        // => 변경할수 없는 문자열 전달시 예외 발생 - 프로그램은 비정상종료
        int n1 = int.Parse("10");    // ok. 성공
//      int n2 = int.Parse("Hello"); // 실패. 예외 발생

        // 방법 #2. int.TryParse()
        // => 성공/실패는 반환 값으로 알려주고
        // => 결과는 out parameter 에 담아주는 메소드

        int value;
        bool b1 = int.TryParse("10", out value);
                                    // 성공시 value 에는 10

        bool b2 = int.TryParse("hello", out value);
                                    // 실패시 value 는 0 으로
                                    // 반환 값으로 false 반환
        if ( b2 ==  false)
        {

        }

    }
}