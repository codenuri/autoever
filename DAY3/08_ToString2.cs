using static System.Console;

/*
class object
{
    public virtual string ToString() 
	{ 
		// 기본 구현은 자신이 타입을 문자열로 반환
	}
}
*/

class Point // : object
{
	private int x = 0;
	private int y = 0;

	public Point(int a, int b) => (x, y) = (a, b);
}

class Program 
{
	public static void Main()
	{
		Point p = new Point(1, 2);

		WriteLine(p);	// 내부적으로 
						// 1. string s = p.ToString() 으로 문자열을 얻고
						// 2. s 를 화면에 출력
    }
}
