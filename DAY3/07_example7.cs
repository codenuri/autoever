using static System.Console;

// 핵심 #8. 디자인 패턴이란 ?
// => 1994 년에 발간된 책의 제목
// => 4명의 개발자가 당시 유행하는 오픈소스를 분석해서
// => 공통으로 사용되던 스타일의 코드에 "이름을 부여" 한것
// => 23개 이름

// 핵심 #9. Prototype 디자인 패턴
// => 견본이 되는 객체를 만들고 복사를 통해서 새로운 객체 생성
// => Clone() 가상함수를 만들어서 사용하는 기술




class Shape
{
    private int color = 0;
    public virtual void Draw() { WriteLine("draw Shape"); }
    public void SetColor(int c) { color = c; }
    public virtual int GetArea() { return -1; }

    public virtual Shape Clone()
    {
        Shape s = new Shape();
        s.color = color; // 모든 필드를 자신과 동일하게 설정
        return s;
    }
}





class Rect : Shape
{
    public override void Draw() { WriteLine("draw Rect"); }
    public override Shape Clone() { return new Rect(); }
}

class Circle : Shape
{
    public override void Draw() { WriteLine("draw Circle"); }
    public override Shape Clone() { return new Circle(); }
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
                    e.Draw();   
                }

            }
            else if ( cmd == 8 )
            {
                Console.Write("몇번째 도형의 복사본을 생성 할까요 >> ");

                int k = int.Parse(Console.ReadLine());

                // k 번째 도형의 복사본을 생성해서 s 에 추가 합니다.
                // 어떻게 구현해야 할까요 ?
                // k 번째 도형은 뭘까요 ?

                // 방법 #1. is 연산자로 조사하자
                // => 가능한 방법이지만 Triangle 추가시 코드가 변경(추가)된다
                // => OCP 를 만족할수 없는 나쁜 디자인
                /*
                if ( s[k] is Rect )
                {
                    // s[k] 번째 복사본 만들에서 s 에 추가
                }
                else if ( s[k] is Circle )
                {
                }
                */

                // 방법 #2. Don't Ask Do It
                // => 물어보지 말고, 시켜라
                // => k 번째 도형이 어떤 종류인지 알필요 없다. 그냥 시키면 된다

                Shape t = s[k].Clone();

                s.Add(t);

            }

        }
    }
}
