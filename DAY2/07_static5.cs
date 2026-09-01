using static System.Console;


class Car
{
    private int speed = 0;      // instance field : 메모리에 객체당 한개 생성
    private static int cnt = 0; // static field   : 모든 객체가 공유 

    public int GetSpeed()        { return speed; } // instance method : 객체.메소드()
    public static int GetCount() { return cnt; }   // static method : 클래스이름.메소드()

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

        Console.WriteLine("자동차 갯수 : {0}", Car.GetCount()); // 0

        Car c1 = new Car(50);
        Car c2 = new Car(80);

        Console.WriteLine("자동차 갯수 : {0}", Car.GetCount()); // 2
    }
}