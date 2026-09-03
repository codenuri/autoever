using static System.Console;

class MyUtil
{
	// Swap 만드세요
	// => 내부적으로 원본에 대한 R/W 모두 가능해야 한다
	public static void Swap(ref int a, ref int b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
}

class Program
{
    public static void Main()
	{
		int x = 1;
		int y = 2;

        MyUtil.Swap( ref x, ref y ); 

		// 아래 결과가 2, 1이 나오도록 Swap 을 만들어 보세요
		WriteLine($"{x}, {y}");	// 2, 1
				
	}
}