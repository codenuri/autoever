// 접근 지정자
// => private 
// => public
// => protected
// => internal 
// 대부분 언어 : private, public, protected
// C# 특징     : internal


// class 이름 앞에서 접근 지정자 사용가능

//class Shape     // internal class Shape
public class Shape  // 다른 어셈블리에서도 사용가능 - WPF 에서 다시 배우게됩니다
{
    private   int color1 = 0;   // 자신의 메소드 에서만 접근 가능
	protected int color2 = 0;   // 자신의 메소드 + 파생 클래스 메소드 접근 가능
	public    int color3 = 0;   // 누구나 접근 가능

    internal int color4 = 0;    // 현재 어셈블리에서만 접근 가능
    
    int color5 = 0; //  접근 지정자 생략시 디폴트는 internal

    // 어셈블리(Assembly)
    // => 실행파일(.exe), 동적모듈(.dll) 등을 C# 에서 부르는 용어
    // => 현재 소스를 DLL 로 빌드후 다른 실행파일에서 사용할때
    // => color4 는 현재 소스는 접근 가능, 이 DLL 을 사용하는 실행파일에서는안됨
}

class Rect : Shape
{
    public void Draw()
    {
        int c1 = color1; // error
		int c2 = color2; // ok
		int c3 = color3; // ok
    }
}

class Program 
{     
    public static void Main()
    {
        Shape s = new Shape();
       	int c1 = s.color1; // error	
		int c2 = s.color2; // error	
		int c3 = s.color3; // ok	
    }

}
