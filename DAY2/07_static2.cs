using static System.Console;

// 방법 #1. 모든 객체는 생성될때 생성자가 호출된다
// => 갯수를 관리하는 필드를 만들고 생성자에서 ++ 하면 어떨까 ?
// => 실패..!!

// 원인
// => 필드는 객체당 한개씩 생성된다.
// => 아래 Main 에서 c1, c2 의 2개의 자동차를 만들면
// => c1.cnt 와 c2.cnt 는 따로 관리된다.
// => 즉, 자동차당 별도의 cnt 생성

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