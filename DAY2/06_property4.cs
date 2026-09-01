class Person
{
    private int age;

    // set, get 중 한개만 만들어도 됩니다.
    // 아래 코드는 쓰기 전용 프라 퍼티
    public int Age
    {
//      get { return age; }
        set { age = value; }
    }
}
class Program
{
    public static void Main()
    {
        Person p = new Person();

        p.Age = 25;    // ok
        int n = p.Age; // error

        // 결국 age 는 Person 의 내부적으로만 읽어서 사용하고
        // 외부에서는 변경할 기회만 제공하겠다는 의도

        string s = "hello";

        bool b = s.Contains('a'); // 메소드 호출
        int n2 = s.Length;        // 프라퍼티(위의 Age 처럼 만든것)
//      s.Length = 0; // error. 읽기 전용 프라퍼티
    }
}


