class Person
{
    /*
    private int age;
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


