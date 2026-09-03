using static System.Console;

delegate void MyType(int arg);

class Program
{
    public static void SMethod(int arg) => WriteLine("SMethod");
    public        void IMethod(int arg) => WriteLine("IMethod");

    // OS 가 Program.Main() 으로 호출 하므로 객체 전달 안됨
    public static void Main()  // void Main() <== this 가 없다
    {
        // 이전예제 : 다른 클래스의 메소드 호출
        // 이번예제 : 자신의 메소드 호출에 대해서

        // #1. 자신의 static method 호출하기
        Program.SMethod(1); // 정확한 표기법. "클래스이름.메소드이름()"
        SMethod(1);         // 자신과 같은 클래스에 있다면 클래스 이름생략가능

        // Delegate 에 등록시
        MyType f1 = Program.SMethod;    // ok
        MyType f2 = SMethod;            // ok


        // #2. 인스턴스 메소드 호출
        IMethod(1); // error. 객체가 없다

        Program pg = new Program();
        pg.IMethod(1); // ok

        // Delegate 등록
        MyType f3 = pg.IMethod; // ok

        pg.InstanceMethod(1);    //   InstanceMethod(pg, 1)  
    }

	public void InstanceMethod() // void InstanceMethod(Program this)
    {
        // #3. 자신의 인스턴스 메소드 안에서 다른 인스턴스 메소드 호출
        IMethod(1); // ok.. ?? 객체가 필요 하지 않나요 ?
                    // 컴파일러가 "this.IMethod(1)" 로 변경한것

        this.IMethod(1); // ok
	}
}

class Test
{
    private int x = 0;

    public void foo()   // void goo(Test this)
    {
        // 이 함수 안에는 this 가 있으므로 
        // 자신의 모든 멤버 접근 가능
        // 컴파일러가 "this.멤버" 로 변경
        x = 10; // this.x = 10 으로 변경된것
                // 반드시 "누구의 x" 가 되어야 합니다.
    }
    public static void goo()    // void goo() <== this 없음
    {
        // 이 함수 안에서는 this가 없음.
        // 그래서 모든 멤버 접근 못함
        x = 10; // error
                // this.x = 10 안됩니다.
                // goo() 는 this 인자 없음
    }
}