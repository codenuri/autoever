using static System.Console;

class Bike
{
    // private 필드 : 자신의 메소드 안에서만 접근 가능하고
    //                외부 함수에서는 접근 할수 없다
    private int gear = 0;

    public void SetGear(int g)
    {
        gear = g;
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


