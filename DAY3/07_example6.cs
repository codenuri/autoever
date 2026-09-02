using static System.Console;

// 핵심 #7


class Shape
{
    private int color = 0;

    public virtual void Draw() { WriteLine("draw Shape"); }
    public void SetColor(int c) { color = c; }
    public virtual int GetArea() { return -1; }
}





class Rect : Shape
{
    public override void Draw() { WriteLine("draw Rect"); }
}
class Circle : Shape
{
    public override void Draw() { WriteLine("draw Circle"); }
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

                    e.Draw(); // <=
                }

            }
        }
    }
}
