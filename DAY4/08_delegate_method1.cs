using static System.Console;

delegate void MyType(int arg);

class Test
{
    public static void SMethod(int arg) => WriteLine("Test.SMethod");
    public        void IMethod(int arg) => WriteLine("Test_Object.IMethod");
}

class Program
{
    public static void Main()
    {
        Test t = new Test();

        t.IMethod(1);    // "객체이름.메소드이름()"   instance method는 객체이름으로 호출
        Test.SMethod(1); // "클래스이름.메소드이름()" static method는 클래스 이름으로 호출

        // delegate 에 다른 클래스의 메소드 등록하기
        MyType f1 = t.IMethod;      // 객체.인스턴스메소드이름
        MyType f2 = Test.SMethod;   // 클래스이름.스태틱메소드이름

        f1(10); 
        f2(10); 


    }
}
