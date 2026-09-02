using static System.Console;

// 핵심 #7. 다형성의 의미, 장점 - 아래 Main 주석 참고


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

                    e.Draw();   // <= 다형성(Polymorphism)
                                // 동일한 표현식(코드)가 상황(실제객체종류)
                                // 에 따라 다르게 동작하는 것
                                // 새로운 도형(Triangle) 이 추가되어도
                                // 이 코드는 수정되지 않습니다. 
                                // OCP 를 만족하는 좋은 코드

                    // 객체지향 프로그래밍 언어의 3대 특징
                    // 1. 캡슐화 - private/public
                    // 2. 상속   - 기존 타입을 확장해서 새로운 타입설계
                    // 3. 다형성
                }

            }
        }
    }
}
