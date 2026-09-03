using static System.Console;

// C# Parameter Modifier 문법
// => C/C++ 언어의 "call by value", "call by reference" 개념

class MyMath
{
    // 아래 코드는 main 에서 보낸 n1 의 복사본(x) 을 만들어서 사용하는 것
    public static void Inc1(int x)
    {
        // 복사본 변수 x 의 값만 증가
        ++x;    
    }
    // 아래 코드는 복사본을 만들지 않고
    // x 가 Main 에서 보낸 n2 를 가리키는 것(참조)
    public static void Inc2(ref int x)
    {
        ++x; // Main 의 n2 를 증가한것
    }
}

class Program
{
    public static void Main()
	{
		int n1 = 0;
        int n2 = 0;

        MyMath.Inc1(n1);
        MyMath.Inc2(ref n2);

        WriteLine($"{n1}, {n2}"); 
    }
}