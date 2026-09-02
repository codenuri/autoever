using static System.Console;

class Animal
{
    public void Cry() { WriteLine("1. Animal Cry"); }
}

class Dog : Animal
{
    // override : 기반 클래스의 메소드를 파생 클래스가 다시 만드는 것
    public void Cry() { WriteLine("2. Dog Cry"); }
}

class Program
{
    public static void Main()
    {
        Animal a = new Animal();
        Dog d = new Dog();

        a.Cry();    // 1. Animal Cry 호출
        d.Cry();    // 2. Dog Cry 호출

    }
}
