class Person
{
    private int age;

    public int Age
    {
        get { return age; }
        set { age = value; }
    }

    // 프라퍼티의 원리
    // => 위 코드를 보고 컴파일러가 2개의 메소드를 자동생성한것
    // => set_Age(), get_Age() 라는 메소드

    // 아래 코드는 에러.. 이미 컴파일러가 프라퍼티 때문에
    // 이 이름의 메소드를 생성
    
    public void set_Age(int a)
    {
        age = a;
    }
    
}
class Program
{
    public static void Main()
    {
        Person p = new Person();

        p.Age = 10; // 컴파일 시간에 "p.set_Age(10)" 로 변경한것


    }
}


