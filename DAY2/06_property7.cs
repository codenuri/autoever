class Person
{
    private int age;

    // set, get 중 한개만 만들어도 됩니다.
    // 아래 코드는 쓰기 전용 프라 퍼티
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

        p.Age = 25;    
        int n = p.Age; 
   }
}


