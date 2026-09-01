using static System.Console;

class Rect
{
    public int left = 0;
    public int top = 0;
    public int right = 0;
    public int bottom = 0;

    // 아래 규칙은 C++/Java 등 대부분의 언어가 유사
    // 생성자 규칙 #1. 여러개 만들수 있다

    // 생성자 규칙 #2. 사용자가 한개도 만들지 않으면
    //                 컴파일러가 "인자가 없는 생성자 제공(아무일도 안함)"
    //                 따라서 "Rect r = new Rect()" 가능
   
    public Rect(int x1, int y1, int x2, int y2)
    {
        left = x1;
        top = y1;
        right = x2;
        bottom = y2;
        Console.WriteLine("Rect(int, int, int, int)");
    }
    /*
    public Rect()
    {
        // 현재는 필드에서 직접 = 0 했으므로 아래 코드 필요 없지만 설명을 위해
        left = 0;
        top = 0;
        rigth = 0;
        bottom = 0; 
        Console.WriteLine("Rect()");
    }
    */

    public int GetArea()
    {
        return (right - left) * (bottom - top);
    }
}

class Program
{
    public static void Main()
    {
        Rect rc1 = new Rect(1, 1, 10, 10); // 인자가 4개인 생성자 호출
        Rect rc2 = new Rect();             // 인자가 0개인 생성자 호출

    }
}