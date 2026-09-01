using static System.Console;

// 방법 #1. 모든 객체는 생성될때 생성자가 호출된다
// => 갯수를 관리하는 필드를 만들고 생성자에서 ++ 하면 어떨까 ?

class Car
{
    private int speed = 0;
    private int color = 0;

    public int cnt = 0; // 자동차 갯수 관리를 위한 필드

    public Car(int s)
    {
        ++cnt;      // 자동차 객체 생성시 마다 1증가
        speed = s;
    }
}
class Program
{
    public static void Main()
    {
        Car c1 = new Car(50);
        Car c2 = new Car(80);

        Console.WriteLine("자동차 갯수 : {0}", c1.cnt);
    }
}