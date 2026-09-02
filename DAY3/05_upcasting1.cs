// Upcasting 개념
// => 대부분의 언어에서 "가장 중요한 개념" 중의 하나..
// => if 를 이해 하는 것 만큼 중요합니다.


class Animal
{
    public int age = 0;
}

class Dog : Animal
{
    public int color = 0;
}

class Cat : Animal
{
    public int speed = 0;
}

class Program
{
    public static void Main()
    {
        Dog r1 = new Dog(); // ok
//      int r2 = new Dog(); // error

        // 핵심 #1. 기반 클래스 타입의 참조(Reference) 로 파생 클래스 객체를
        //          가리킬수 있다
        // => upcasting 이라는 개념
        // => 되는 이유는 "메모리 그림" 을 그려보면 이해 됩니다

        Animal r3 = new Dog(); // ok


        // 핵심 #2. 컴파일러는 컴파일 시간에는 r3 대상체의 타입을 알수 없다
        //          r3 자체의 타입이 Animal 이라는 것만 알수 있다

        // => 이유는 "아래 코드와 같이 실행시간 변경 가능" 하므로
        // if ( 사용자 입력값 == 1 ) r3 = new Cat();


        // 핵심 #3. Animal 타입인 r3 를 사용해서는
        //          Animal 고유의 멤버만 접근 가능하다.
        //          Dog 가 추가한 멤버는 접근 못함
        // => 이유는 C# 은 "static type check" 를 하기 때문에

        // static  type check : 타입에 관한 확인을 컴파일 시간에 하는것
        // dynamic type check : 타입에 관한 확인을 실행   시간에 하는것

        // 즉, C# 은 "r3.color = 0" 이 유효한지를 컴파일 시간에 확인
        // => 컴파일러는 r3 자체가 Animal 이라는 것만 알고
        // => r3 대상체가 Dog 라는 확신이 없다
        // => 그래서 "r3.color = 0" 은 허용 안함

        r3.age   = 10;  // ok
        r3.color = 0;   // error

        // 핵심 #4. Animal 타입의 Reference 인 r3 을 가지고
        //        Dog 의 고유 멤버에 접근하려면 r3 를 Dog 타입으로 캐스팅해서
        //        사용해야 한다.
        // => 컴파일러에게 대상체가 Dog 라고 알려 주는것

        ((Dog)r3).color = 1;
        // => 단 위 코드는 r3 의 대상체가 Dog 가 아닌 경우 runtime error
        // => 확신이 있을때만 사용


        // 핵심 #5. 대상체의 타입에 대해서 확신이 없다면 조사후 캐스팅하세요
        // => is 연산자
        if ( r3 is Dog )
        {
            ((Dog)r3).color = 2;

            // 이제 캐스팅해서 사용
            Dog d = (Dog)r3;
            d.color = 2;
        }
        
        // 위 코드를 간결하게 하려면 아래 처럼
        if ( r3 is Dog d )
        {
            d.color = 2;
        }

    }
}



