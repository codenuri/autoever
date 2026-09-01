class Point
{
    private int x = 0;
    private int y = 0;
    
    // this 활용 #1. 이름 충돌이 있을때 필드 임을 명확히 하기 위해
    // => 이름 충돌이 없어도 메소드가 복잡하다면
    //    중간에  "x = a" 로 했을때 x 가 필드인지 지역변수인지 헷갈릴수 있습니다.
    //            "this.x = a" 로 하면 명확 합니다. 권장
    public void Set(int x, int y)     
    {
//      x = x;    // 인자의 x = 인자의 x                    

        this.x = x;
        this.y = y;                          
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
