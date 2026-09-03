using static System.Console;

delegate void MyType(int arg);

class Program
{
    public static void SMethod(int arg) => WriteLine("SMethod");
    public        void IMethod(int arg) => WriteLine("IMethod");

    public static void Main()
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

        pg.InstanceMethod(1);        
    }

	public void InstanceMethod()
	{
        // #3. 자신의 인스턴스 메소드 안에서 다른 인스턴스 메소드 호출
	}
}
