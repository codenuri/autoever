class Person
{
    /*
    private int age = 0;
    public int Age
    {
        get { return age; }
        set { age = value; }
    }
    */

    // 위 처럼 별도의 logic 을 추가로 가지지 않은 프라퍼티가 필요하면
    // 아래 처럼 한줄만 만들면 됩니다.
    // => 아래 한줄이 위 주석 코드와 완전히 동일
    // => auto-implemented property 라고 합니다.
    public int Age { get; set; } = 0;

    // 추가적인 로직이 없다면 "public 필드"로 해도 되지 않나요?
    // => public 필드 보다 위 코드가 훨씬 좋습니다.

    // 현재는 추가로직이 없지만
    // => 미래에 추가로직이 필요하면
    // => 이 클래스만 수정하면 되고
    // => Main 코드는 수정될필요 없습니다.
}

class Program
{
    public static void Main()
    {
        Person p = new Person();

        p.Age = 25;    
        int n = p.Age; 
   }
}


