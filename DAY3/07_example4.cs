using static System.Console;

// 핵심 #4. Shape 타입인 e 를 Rect, Circle 로 캐스팅해서 사용하는 코드
// => Main 함수 에서 "if ( cmd == 9 )" 코드 참고
// => 이 코드의 문제점은 무엇일까요 ?

// 핵심 #5. OCP 규칙 - 객체지향 프로그래밍 설계의 핵심 원리 5개 중 한개
// => 기능 확장에는 열려있고(Open, 모듈/클래스 등이 추가되어도)
// => 코드 수정에는 닫혀야 (Close, 기존 코드는 수정되지 않도록)
// => 만들라는 원칙(Principle)

// Open Close Principle( 개방폐쇄의 법칙)

// 아래 코드는 Triangle 이 추가되면 Main 의 if 문이 변경됩니다.
// => OCP 위반
// => 나쁜 디자인


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
