class Person
{
    private int age;

    // 아래 코드가 핵심
    // 1. 1번째 줄만 보면 필드 같지만 아래줄에 { 이 있습니다.
    // 2. { 있으므로 메소드 같지만 () 가 없습니다
    // => 필드도 아니고 메소드도 아닌 프라퍼티 만드는 문법
    public int Age
    {
        get { return age; }
        set { age = value; }
    }
}
class Program
{
    public static void Main()
    {
        Person p = new Person();

        // Property 는 필드 처럼 사용하면 됩니다.
        p.Age = 25;     // 쓰는 작업. Age 의 set {} 호출
                        // 우변의 25 는 약속된 이름인 "value" 로 전달

        int n = p.Age;  // 읽는 작업. Age 의 get {} 호출

        // 프라퍼티
        // 만들때는 메소드와 유사하지만
        // 사용할때는 필드와 유사하다
    }
}


