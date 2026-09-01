class Person
{
    private int age;

    // #1. 이름 관례
    // => 프라퍼티 이름은 어떠한 이름도 사용가능
    // => 관례는 "필드를 모두 소문자로,
    //            프라퍼티는 필드와 동일이름 사용하고 1글자를 대문자로"

    public int Age
    {
        // #2. 구현이 간단하면 "expression bodied" 사용가능
//      get { return age; }
        get => age;

        // #3. 구현이 복잡하면 일반 메소드 처럼 여러줄로 구현
        set { 
               if( value >0 && value < 200)
                  age = value; 
        }
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


