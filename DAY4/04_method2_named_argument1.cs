
class Rect
{
    public void Set(int x, int y, int width, int height) { }
}

class Program
{
    public static void Main()
    {
        Rect rc = new Rect();

        // 아래 Set() 호출에서 인자가 각각 어떤 의미일지 예측해 보세요
        // => 명확하지 않아서 도움말이 필요할수 있습니다.
        rc.Set(1, 1, 10, 10);

        // 아래 처럼 사용하면 어떨까요 ?
        // => named argument 라는 문법
        // => C#, Objective-C 언어에서 볼수 있는 문법
        // => 대부분의 다른 언어는 이 문법 없음.
        rc.Set(x:1, y:1, width:10, height:10);

        // 일부요소만 named 가능
        rc.Set(1, 1, width:10, height:10);

    }
}
