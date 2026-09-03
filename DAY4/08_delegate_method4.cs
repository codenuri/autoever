using static System.Console;

// multicast 

delegate void MyFunc(int arg);

class Program
{
	public static void SMethod(int arg) => WriteLine("Program.SMethod");

	public static void Main()
	{	
		MyFunc f = Test.SMethod;
		f += Program.SMethod;

		// 등록된 2개의 메소드 호출
		f(10); 
	}
}

class Test
{
    public static void SMethod(int arg) => WriteLine("Test.SMethod");
    public void IMethod(int arg) => WriteLine("Test_Object.IMethod");
}
