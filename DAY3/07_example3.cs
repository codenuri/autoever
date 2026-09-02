using static System.Console;


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

        while(true)
        {         
            int cmd = int.Parse(Console.ReadLine()); // 정수 입력받기

            if      ( cmd == 1 ) s.Add(new Rect());
            else if ( cmd == 2 ) s.Add(new Circle());
            else if ( cmd == 9 )
            {
                foreach (var e in s)
                    e.Draw();
            }
        }
    }
}
// 컴파일 하면 왜 어디서? 왜 에러가 발생할까요 ?
// 해결책은 뭘까요 ?