using static System.Console;



class Animal
{
    public void Cry() { WriteLine("1. Animal Cry"); }
}
class Dog : Animal
{
    public new void Cry() { WriteLine("2. Dog Cry"); }
}

class Program
{
    public static void Main()
    {
        Animal ad = new Dog();

        // ad 자체의 타입            : Animal
        // ad 가 가리키는 대상체 타입 : Dog

        // 아래 코드는 어느 메소드를 호출할까 ?
        // 여러분이 언어의 설계자라면 어느 메소드를 호출하게 만들지 생각해보세요
        ad.Cry(); // ?

        // C#/C++ : Animal Cry
        // Java, Python, Swift, Kotlin, Objective-C... 대부분의 언어 : Dog Cry
    }
}


// ad.Cry() 를 실제 어떤 함수 와 연결할것인가 ?
// => 함수(메소드) 바인딩 이라는 이론

// 1. static binding



// 2. dynamic binding