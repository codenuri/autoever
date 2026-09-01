using static System.Console;


// 타입 설계의 원칙
// => 잘못 사용하기 어렵게, 제대로 사용하기 쉽게 설계 하라!
// => 타입을 만드는 사람은 초보자가 사용해도 쉽고 안전하게 설계해야한다

class Bike
{
    // private 필드 : 자신의 메소드 안에서만 접근 가능하고
    //                외부 함수에서는 접근 할수 없다
    private int gear = 0;   
}

class Program
{
    public static void Main()
    {
        Bike b = new Bike();

        b.gear = -10;   // 사용자가 실수했다.
                        // 현실세계에 존재 할수 없는 잘못된 상태를 가지는 객체가 탄생
                        // private 필드 라면 컴파일 에러

    }
}


