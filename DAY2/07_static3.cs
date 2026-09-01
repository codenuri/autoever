using static System.Console;

// 필드의 2가지 종류
// 1. 인스턴스 필드(instance field)
// => static 을 붙이지 않은 것
// => 객체당 한개씩 생성
// => 객체의 속성을 관리(색상, 속도)

// 2. static 필드(정적 필드)
// => static 을 붙인것
// => 모든 객체가 공유
// => 각각 객체의 속성이 아닌 클래스 자체의 속성




class Car
{
    private int speed = 0;
    private int color = 0;

//  public int cnt = 0;         // 객체당 한개씩 생성되는 필드

    public static int cnt = 0;  // 모든 객체가 공유하는 필드
                                // 1. 자동차를 만들지 않아도 메모리에 있고
                                // 2. 자동차를 여러개 만들어도 각각의 객체메모리에는
                                //    포함안됨
                                // => 접근지 "Car.cnt" 접근



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
        Console.WriteLine("자동차 갯수 : {0}", Car.cnt); // 0

        Car c1 = new Car(50);
        Car c2 = new Car(80);

        Console.WriteLine("자동차 갯수 : {0}", Car.cnt); // 2
    }
}