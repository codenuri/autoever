using static System.Console;
// static field
// 1. 객체가 없어도 메모리에 생성된다
// 2. 모든 객체가 공유 한다

// static method
// 1. 객체가 없어도 호출 가능

class Car
{
    private int speed = 0;
    private static int cnt = 0;

    // 다음 코드에서 컴파일 에러를 모두 찾으세요
    // 아래 메소드가 호출된것은, 객체가 있었다는 것
    // "c1.foo()"
    public void foo()   // void foo(Car this)
    {
        speed = 0;  // 1    ok  this.speed = 0
        cnt = 0;    // 2    ok  Car.cnt = 0
        goo();      // 3    ok  Car.goo()
    }
    // 객체가 없어도 호출 가능한 함수
    // => static method 는 this 가 추가되지 않은 메소드
    // => instance field 접근은 반드시 this 가 필요 합니다.
    //    (어느 객체의 필드 인가 ? 알아야 합니다. 위 코드 참고)
    public static void goo()    // void goo() 
    {
        speed = 0;  // 4  error. 객체가 있어야만 메모리에 존재
        cnt = 0;    // 5  ok.    객체가 없어도 메모리에 존재 한다
        foo();      // 6  error
    }
}
class Program
{
    public static void Main()
    {
        Car c = new Car();
        c.foo();    // foo(c)  => foo 인자로 객체 추가

        Car.goo();  // 호출시 사용한 객체가 없습니다.
                    // 그래서 인자로 추가되는 것이 없습니다.
                    // goo()

    }
}