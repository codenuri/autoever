using static System.Console;

class Animal
{
    // non-virtual : 기본 정책은 static binding 으로 동작
    //               대상체 타입이 아닌 "Reference 변수 타입" 으로 결정
    //               "new" 를 사용해서 재정의
    public void Cry1() { WriteLine("Animal Cry1"); }

    // virtual : dynamic binding 해달라는 의미
    //           대상체 타입에 따라 메소드 결정
    //           "new" 가 아닌 "override" 를 붙여서 재정의
    public virtual void Cry2() { WriteLine("Animal Cry2"); }
}

class Dog : Animal
{
    public void Cry1() { WriteLine("Dog Cry1"); }
    public void Cry2() { WriteLine("Dog Cry2"); }
}

class Program
{
    public static void Main()
    {
        Animal ad = new Dog();

        ad.Cry1();  // ?
        ad.Cry2();  // ?
    }
}

