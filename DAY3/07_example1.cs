using static System.Console;

// 파워 포인트 같은 프로그램을 객체지향 프로그램으로 설계해 봅시다.

// 핵심 #1. 필요한 도형타입을 클래스로 설계

class Rect
{
    // int x, y, w, h, 생성자 등은 생략, 가상함수 활용에 집중

    public void Draw() { WriteLine("draw Rect");  }
}
class Circle
{
    public void Draw() { WriteLine("draw Circle"); }
}
class Program
{
    public static void Main()
    {
        Rect   r = new Rect();
        Circle c = new Circle();

        r.Draw();
        c.Draw();
    }
}