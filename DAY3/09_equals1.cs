using static System.Console;

 class Point 
 {
	private int x = 0;
	private int y = 0;
	public Point(int a, int b) => (x, y) = (a, b);
}

class Program
{
	public static void Main() 
	{
		// 객체의 동일성에는 2가지 개념이 있습니다. - 125 page 그림참고
		// 1. "객체 자체가 동일" 한가 ?
		// 2. 객체는 다르지만 상태가 동일한가 ?

		// p1, p2 는 동일객체 입니다.
		Point p1 = new Point(1,2);
		Point p2 = p1;

		// p3, p4 는 동일 객체 아니지만
		// 상태는 동일합니다.
		Point p3 = new Point(1,2);
		Point p4 = new Point(1,2);
	}
}
