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

    public override string ToString()
    {
		// 자신의 상태를 문자열로 만들어서 반환
		return string.Format("x = {0}, y = {1}", x, y);
    }
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

// object 클래스에는 
// => 객체의 상태를 문자열로 변경하기 위한 ToString() 가상 메소드 제공

// => 그런데, 기본 구현은 "클래스 이름" 을 문자열로 반환
// => 사용자가 자신의 타입을 만들때 이 기능을 다시 만들고 싶으면
// => ToString() 을 override 해서 상태(x,y) 를 문자열로 반환하세요




