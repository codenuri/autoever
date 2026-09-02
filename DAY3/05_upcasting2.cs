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

        List<Dog> s1 = new List<Dog>();
        
        s1.Add(new Dog());
        s1.Add(new Dog());

    }
}



