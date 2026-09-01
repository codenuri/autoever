using static System.Console;

// 캡슐화(encapsulaton)
// => 타입을 만들때
// => 상태를 나타내는 데이터는 private 에 놓아서 외부에 잘못된 사용때문에
//    객체의 상태가 불안해 지는 것을 막는다

// => 객체의 상태는 잘 정의된 메소드에 의해서면 변경 될수 있다

// 정보 은닉(information hiding)
// => Bike 사용자는 필드(gear) 에 대해서는 알 필요 없다
// => 메소드만 알면 된다.

// private : 자신의 메소드안에서만 접근 가능
// public  : 어디서든 접근 가능
// => C#/Java/C++/Rust/Swift 등 대부분의 언어 지원
// => Python 에 없음



class Bike
{
    // private 필드 : 자신의 메소드 안에서만 접근 가능하고
    //                외부 함수에서는 접근 할수 없다
    private int gear = 0;

    // public : 어디에서도 접근 가능
    //          메소드 만들때 private 도 가능하지만 주로 public
    //          public 이므로 Main에서 SetGear() 호출 가능
    public void SetGear(int g)
    {
        // 자신의 상태를 변경하기 전에 인자값의 유효성을 먼저 확인합니다.
        // => 아래 코드는 인자값이 유효한 경우만 자신의 상태 변경
        // => 그외에는 무시하는 코드 ( 보통은 예외 발생이 더 좋은 방법)
        if (g > 0 && g < 20)
        {
            gear = g;
        }
    }
}
class Program
{
    public static void Main()
    {
        Bike b = new Bike();

//      b.gear = -10;  // error

        b.SetGear(-10);
    }
}


