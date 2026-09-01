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
	public SPoint(int a, int b) { x = a; y = b;}	
}

// 핵심 : 아래 코드의 메모리 모양
class Program 
{
	public static void Main()
	{	

		// 아래 코드의 메모리를 그릴수 있어야 합니다.(교재 37 page)
		CPoint cp1 = new CPoint(1, 1);
		CPoint cp2 = cp1;	// 같은 객체를 가리키게 됨
		
		cp1.x = 2;

		WriteLine($"{cp1.x} {cp2.x}"); 

		SPoint sp1 = new SPoint(1, 1);
		SPoint sp2 = sp1;

		sp1.x = 2;
	
		WriteLine($"{sp1.x} {sp2.x}"); 
	}
}
