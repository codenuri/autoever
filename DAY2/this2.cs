class Point
{
    private int x = 0;
    private int y = 0;
    
    // this 활용 #1. 이름 충돌이 있을때 필드 임을 명확히 하기 위해
    public void Set(int x, int y)     
    {                                 
        x = x;                        
        y = y;                        
    }                                 
}

class Program
{
    public static void Main()
    {
        Point p1 = new Point();
        Point p2 = new Point();

        p1.Set(1, 2); 
        p2.Set(1, 2);
    }
}
