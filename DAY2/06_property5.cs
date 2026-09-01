class Person
{
    private int age;

    public int Age
    {
        get { return age; }
        set { age = value; }
    }

    public int Person() => age = 0;      // 인자 없는 생성자
    public int Person(int a) => age = a; // 인자 1개 생성자
}
class Program
{
    public static void Main()
    {
        Person p1 = new Person();   // 인자 없는 생성자 호출
        Person p2 = new Person(20); // 인자 1개 생성자 호출
        Person p3 = new Person { Age = 20 };
                        // 1. Person p3 = new Person()
                        // 2. p3.Age = 20

        // 여러개 property 가 있으면 아래 처럼도 가능
//      Person p4 = new Person { Age = 20, Name="kim" };

    }
}


