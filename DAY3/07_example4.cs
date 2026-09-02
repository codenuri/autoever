using static System.Console;

// 핵심 #4

class Shape
{
    private int color = 0;
}

class Rect : Shape
{
    public void Draw() { WriteLine("draw Rect"); }
}
class Circle : Shape
{
    public void Draw() { WriteLine("draw Circle"); }
}
class Program
{
    public static void Main()
    {
        List<Shape> s = new List<Shape>();

        while (true)
        {
            int cmd = int.Parse(Console.ReadLine()); 

            if (cmd == 1) s.Add(new Rect());
            else if (cmd == 2) s.Add(new Circle());
            else if (cmd == 9)
            {
                foreach (var e in s)
                {
                    // e.Draw();  // error

                    // 해결책 #1. Shape 타입인 e 를 Rect, Circle 타입으로 캐스팅해서 사용

                    // ((Rect)e).Draw(); // 무조건 캐스팅 하면 안되고, 조사한후 캐스팅

                    if ( e is Rect r ) // if ( e is Rect ) Rect r = (Rect)e 
                    {
                        r.Draw();
                    }
                    else if ( e is Circle c)
                    {
                        c.Draw();
                    }
                }                                   
            }
        }
    }
}
// 실행해서
// 1, 2, 1, 2, 몇번 입력후 9번 입력해 보세요
