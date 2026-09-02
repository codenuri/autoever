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

// 1. static binding : 컴파일 시간에 컴파일러가 호출될 메소드 결정
//                     [핵심] 컴파일러는 ad 자체의 타입이 Animal 이라는 것은 안다
//                            하지만, 대상체의 타입은 알수 없다
//                      그래서, 컴파일러가 결정하면 Animal Cry 호출


// 2. dynamic binding : 실행시간에 메소드를 결정
//                      컴파일 할때는 "ad 가 가리키는 대상체를 조사하는 
//                      기계어 코드를 생성"
//                      실행할때 조사 코드를 실행해서 나오는 결과를 가지고 
//                      메소드 결정
//                      대상체가 Dog 라면 Dog Cry 호출