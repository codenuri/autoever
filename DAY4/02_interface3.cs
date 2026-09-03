using static System.Console;

// C# 에는 서로 다른 타입에서 같은 이름의 메소드를 제공하는 경우가 많습니다.
// 이때 이름을 약속하기 위해 모두 인터페이스 기반으로 설계되었습니다.

// C# 내부에 아래 코드 제공
/*
interface IComparable
{
	int CompareTo(object obj);
}
// 이제 크기비교가 가능한 모든 타입은 "IComparable" 인터페이스를 구현하기로 약속
class string : IComparable
{
	public int CompareTo(object obj)
	{
		// 자신의 데이타에 맞게 구현
	}
}
struct Int32 : IComparable
{
    public int CompareTo(object obj)
	{
		// 자신의 데이타에 맞게 구현
	}
}
*/

class Program 
{
	public static void Main()
	{
		int n1 = 10;
		int n2 = 20;

		string s1 = "AAA";
		string s2 = "BBB";

		// 두 변수의 크기를 비교하는 방법. 

		// #1. 비교 연산자(<, >,...) 사용
		// => 수치 타입만 가능.
		bool b1 = n1 < n2;	// ok
		bool b2 = s1 < s2;  // error

		// #2. CompareTo() 메소드 사용
		// => "크기 비교" 라는 개념이 가능한 대부분의 타입은 제공
		int ret1 = n1.CompareTo(n2); // ok  
		int ret2 = s1.CompareTo(s2); // ok

		// n1.CompareTo(n2) 의 결과값
		// n1 > n2  이면 양수(1)
		// n1 == n2 이면 0
		// n1 < n2  이면 음수(-1)

		M1(n1); // ok
        M1(s1); // ok
    }
	
	// 메소드 인자로 "인터페이스 이름" 사용시
	// => 인터페이스를 구현한 모든 타입을 받을수 있습니다.
	public static void M1(IComparable ic)
	{
	}

}
