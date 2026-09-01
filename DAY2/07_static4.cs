using static System.Console;




class Car
{
    private int speed = 0;
    private int color = 0;

//  public static int cnt = 0;   // 이렇게 하면 외부에서 "Car.cnt = -10" 도 가능
    private static int cnt = 0;  // 안전하게 하려면 private 으로

//  public int GetCount() { return cnt; }   // instance method
                                            // "객체.GetCount()"로 호출
                                            // 객체가 있어야 호출가능

    public static int GetCount() { return cnt; }   // static method
                                            // "클래스이름.GetCount()"
                                            // 객체가 없어도 호출 가능
                                            // "Car.GetCount()"

    public Car(int s)
    {
        ++cnt;
        speed = s;
    }
}
class Program
{
    public static void Main()
    {
//      Car.cnt = -10;

        Console.WriteLine("자동차 갯수 : {0}", Car.cnt); // 0

        Car c1 = new Car(50);
        Car c2 = new Car(80);

        Console.WriteLine("자동차 갯수 : {0}", c1.GetCount() ); // 2
    }
}