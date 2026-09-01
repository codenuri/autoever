using static System.Console;

class CPoint
{
	public int x;
	public int y;
	public CPoint(int a, int b) { x = a; y = b;}
}
struct SPoint
{
	public int x;
	public int y;
	public SPoint(int a, int b) { x = a; y = b; }	
}

class Program 
{
	public static void Main()
	{
		// 38 page 그림
		CPoint cp1;	// 객체생성이 아님. reference 변수만 생성

		CPoint cp2 = new CPoint(1, 1); // 객체도 생성


		SPoint sp1;	//	스택에 x,y 가 있지만 생성자 호출 안됨 초기화 안됨 

		SPoint sp2 = new SPoint(1, 1);	// 생성자 호출됨
		
		// 핵심 : 에러를 모두 찾으세요
		int a = cp1.x;	// error
		cp1.x = 2;		// error   x,y 자체가 메모리에 없다(38 page 그림참고)

		int b = sp1.x;	// error. 초기화 안됨
		sp1.x = 2;		// ok     x 자체는 있으므로 쓰기는 가능
		int c = sp1.x;	// ok     윗줄에서 값을 넣었으므로 이제 읽기 가능

		int d = sp2.x;	// ok
		sp2.x = 2;		// ok

	}
}
