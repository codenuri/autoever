class Person
{
    private int age;

    // 아래 코드가 핵심
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
