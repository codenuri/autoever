class Animal
{
    public int age = 0;
}

class Dog : Animal
{
    public int color = 0;
}

class Cat : Animal
{
    public int speed = 0;
}

class Program
{
    public static void Main()
    {
        // Upcasting 은 언제 사용하는가 ?

        // #1. 동종을 보관하는 Collection 만들기
        List<Dog> s1 = new List<Dog>(); // Dog 객체만 보관하는 Collection        
        s1.Add(new Dog());
        s1.Add(new Dog());

        List<Animal> s2 = new List<Animal>();   // 모든 동물을 보관하는 Collection
                                                // 동종을 보관하는 Collection 만드는기술
        s2.Add(new Dog());                      // 동종 : 동일 기반 클래스를 사용하는 타입
        s2.Add(new Cat());

        // 활용 #2. 동종을 처리하는 함수 만들기
        // [참고] Main 함수 안에 다시 함수 만들기 가능합니다.

        //void NewYear(Dog d)    // 인자로 Dog 객체만 전달 가능  
        void NewYear(Animal d)   // 인자로 모든 동물객체를 전달 가능  
        {
            ++d.age;
        }

        NewYear(new Dog());
        NewYear(new Cat());
    }
}

// List : 실행시간에 항목을 추가할수 있는 배열로 생각하면 됩니다.

