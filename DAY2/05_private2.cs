using static System.Console;

class Bike
{
    // private 필드 : 자신의 메소드 안에서만 접근 가능하고
    //                외부 함수에서는 접근 할수 없다
    private int gear = 0;

    public void SetGear(int g)
    {
        // 자신의 상태를 변경하기 전에 인자값의 유효성을 먼저 확인합니다.
        // => 아래 코드는 인자값이 유효한 경우만 자신의 상태 변경
        // => 그외에는 무시하는 코드 ( 보통은 예외 발생이 더 좋은 방법)
        if (g > 0 && gear < 20)
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


