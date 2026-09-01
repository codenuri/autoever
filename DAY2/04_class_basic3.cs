using static System.Console;

class Rect
{
    public int left = 0;
    public int top = 0;
    public int right = 0;
    public int bottom = 0;

    // tuple deconstruction 기술과 expression bodied 기술로 구현한 생성자 모양
    // => 실전에서 널리 사용되는 표현
    public Rect(int x1, int y1, int x2, int y2)
        => (left, top, right, bottom) = (x1, y1, x2, y2);

    // 아래 코드도 수정해 보세요
    public Rect()
        => (left, top, right, bottom) = (0, 0, 0, 0);


    public int GetArea()
    {
        return (right - left) * (bottom - top);
    }
}

class Program
{
    public static void Main()
    {
        Rect rc1 = new Rect(1, 1, 10, 10); 
        Rect rc2 = new Rect();             

    }
}