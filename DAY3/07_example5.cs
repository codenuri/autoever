using static System.Console;

// 핵심 #6. 모든 파생 클래스(도형)의 공통의 규칙은 기반 클래스(Shape) 에도
//          있어야 한다
// => 문법적인 제약이 아닌 디자인 규칙
// => 그래야 Shape 타입으로 해당 특징(Draw()) 사용 가능

// 핵심 #7. 기반 클래스 메소드중에서 파생 클래스가 다시 만들게 된다면
//          대부분 virtual 로 만들어야 한다.

// => 그래야 "Shape e = new Rect()" 에서 "e.Draw()" 가 Rect 호출
// => 파생 클래스에서 재정의 할때 "override" 사용

class Shape
{
    private int color = 0;

    public virtual void Draw() { WriteLine("draw Shape"); }

    // 아래 메소드는 virtual 로 할까요 ? non-virtual 로 할까요 ?
    // => 파생 클래스가 다시 만들 필요 없다. non-virtual
    public void SetColor(int c) { color = c; }

    // => 각 도형은 면적을 구하는 방법이 다르다
    // => 파생 클래스가 override 해서 자신에 맞는 코드를 제공해야 한다.
    // => virtual
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
