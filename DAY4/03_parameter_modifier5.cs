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
        int n2 = int.Parse("Hello"); // 실패. 예외 발생


        // #2. int.TryParse()
    }
}