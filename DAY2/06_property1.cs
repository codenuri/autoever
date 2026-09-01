// 프라퍼티(Property) 문법
// => 다른 언어에는 없는 "C# 만의 독특한 문법"
// => C# 진영에서는 장점으로 많이 강조하고 널리 사용

// public field vs setter/getter

// #1. public field
// => 외부에서 "age" 를 직접 접근 가능
// => 외부에서 잘못 사용시 "age" 의 상태가 불안해 질수 있다
class Person1
{
    public int age;
}

// #2. private field 아 Set/Get 메소드 제공(setter, getter 라고 표현)
// => 외부에서 age 를 변경시, 유효한 값을 인자로 보낼때만 상태 변경됨
class Person2
{
    private int age;

    public int GetAge() => age;

    public void SetAge(int value)
    {
        if (value > 0)
            age = value;
    }
}

class Program
{
    public static void Main()
    {
        Person1 p1 = new Person1();
        Person2 p2 = new Person2();

        // #2. 가 안전한 버전입니다.
        // => 그런데, 아래 코드중 보다 읽기 쉽고 직관적인 코드는 ?

        // #1. publie field
        p1.age = 10;
        int n1 = p1.age;


        // #2.setter/getter 사용
        p2.SetAge(10);
        int n2 = p2.GetAge();


        // 결론
        // #2 가 안전하지만
        // #1 이 읽고 이해 하기 쉽습니다

        // 안전한 #1 은 없을까요 ?
        // => property 문법
    }
}
