using static System.Console;

// 이시간 이후 부터 ~ 내일 까지
// => 타입을 만드는 데 사용하는 "class" 와 관련된 문법을 배우게 됩니다.


// 핵심. 생성자 이야기 
class Rect
{
    public int left = 0;
    public int top = 0;
    public int rigth = 0;
    public int bottom = 0;

    // 생성자 : 클래스 이름과 동일한 이름의 함수
    // 특징   : 객체를 생성하면 자동으로 호출되는 함수 (파이썬의 init)
    public Rect(int x1, int y1, int x2, int y2)
    {
        left   = x1;
        top    = y1;
        right  = x2;
        bottom = y2;
    }

    public int GetArea()
    {
        return (right - left) * (bottom - top);
    }
}

class Program
{
    public static void Main()
    {
        /*
        Rect rc = new Rect();
        rc.left = 1;
        rc.top = 1;
        rc.rigth = 10;
        rc.bottom = 10;
        */

        Rect rc = new Rect(1, 1, 10, 10); // 이순간 생성자가 호출됩니다
                                          // 결국 위 주석과 동일한 기능 수행

        int ret = rc.GetArea();

        Console.WriteLine($"{ret}"); 
    }
}