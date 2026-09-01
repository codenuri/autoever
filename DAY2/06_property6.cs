class Person
{
    private int age;

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

        p.Age = 10;


    }
}


