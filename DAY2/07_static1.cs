using static System.Console;

// static 멤버 개념
// => 대부분의 객체지향 프로그래밍 언어의 공통 개념


// Car 객체(자동차)를 몇대나 만들었는지 알고 싶다

class Car 
{
    private int speed = 0;
    private int color = 0;

    public Car(int s)
    {
        speed = s;
    }
}

class Program
{
    public static void Main()
    {
        Car c1 = new Car(50);
        Car c2 = new Car(80);

        // 현재까지 실행하면서 자동차 객체를 몇개 생성했는지 알고싶다 !!
        // => 다음 소스부터 해결
    }
}