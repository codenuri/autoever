using static System.Console;

// 핵심 #6. 모든 파생 클래스(도형)의 공통의 규칙은 기반 클래스(Shape) 에도
//          있어야 한다
// => 문법적인 제약이 아닌 디자인 규칙
// => 그래야 Shape 타입으로 해당 특징(Draw()) 사용 가능


class Shape
{
    private int color = 0;

    public void Draw() { WriteLine("draw Shape"); }
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
            int cmd = int.Parse(Console.ReadLine()); // 정수 입력받기

            if (cmd == 1) s.Add(new Rect());
            else if (cmd == 2) s.Add(new Circle());
            else if (cmd == 9)
            {
                foreach (var e in s) 
                    e.Draw();       
                                     
            }
        }
    }
}
