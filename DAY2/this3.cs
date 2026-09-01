class Point
{
    private int x = 0;
    private int y = 0;

    // this 활용 #2. this 를 반환 하는 함수
    // => 자바에서 널리 사용하는 "빌더 기술"
    public Point SetX(int a)
    {
        x = a;
        return this;
    }
    public Point SetY(int a)
    {
        y = a;
        return this;
    }
}
class Program
{
    public static void Main()
    {
        Point p = new Point();

        // 메소드가 this 를 반환하면 메소드 호출을 연속적으로 할수 있습니다.
        // => Method chainging 이라는 기술입니다.
        // => 요즘 다양한 언어에서 아주 널리 사용되는 기술입니다.
        p.SetX(3).SetY(3).SetX(3).SetY(5);

        // java 에서 아래 처럼 많이 사용합니다
        // Person p2 = new Person();
        // p2.SetName("kim").SetAge(30).SetHegith(180);
    }
}
