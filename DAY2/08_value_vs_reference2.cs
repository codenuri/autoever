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

// C# 이 가진 모든 타입은 아래 2개로 분류 합니다

// Reference Type : class 문법으로 만든 것
//		=> 객체 자체는 힙에 생성하고
//		=> 스택에 있는 레퍼런스변수가 힙 객체의 주소를 관리하는 것
//		=> C 언어의 포인터

// Value Type : struct(구조체) 문법으로 만든것
//		=> 객체 자체가 스택에 존재

// Point p1 = p2 연산시  
// reference type : 주소를 복사 한것, 같은 객체를 공유하게 됨
// value type     : 객체를 복사 한것, x,y 값은 동일하지만 다른 객체
// => 교재 37 page 그림