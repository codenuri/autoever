using static System.Console;

class Example
{
    // ref, out 이 없이 받으면 "복사본" 생성
    // => Main 에서 전달한 변수를 변경하지는 못함
    // => 함수 내부에서만 사용 - in parameter
    public static void no_modifier_parameter(int x)
    {
        int n = x; // ok. read 가능
        x = 0;     // ok. write 가능. 복사본에 쓰기
    }

    // out parameter
    // => 값을 담아 주겠다는 의미
    // => 호출자는 초기화 되지 않은 변수도 전달 가능
    public static void out_parameter(out int x)
    {
//      int n = x;  // error. 읽을수 없다
        x = 0;      // ok.    쓰기는 가능
                    // 단, 쓰는 코드가 없으면 에러
                    // 즉, out parameter 는 반드시 값을 담아주어야 한다
    }

    // ref parameter
    // => 메소드 내부에서 R/W 모두 사용하겠다는 의도
    // => 호출자는 초기화 되지 않은 변수는 전달할수 없다
    public static void ref_parameter(ref int x)
    {
        int n = x;  // ok. Read 가능
        x = 0;      // ok. Write 가능

        // R/W 하는 코드가 모두 없어도 에러 아님.
        // 어차피 x 에 보낸 변수는 초기화 되어 있음
        // Main 에서 계속 사용해도 안전
    }
}

class Program
{
	public static void Main()
	{
		int n1;		
		int n2 = 0;

        // out parameter 의 전달은 "초기화 되지 않아도 가능"
//     Example.out_parameter(out n1); // ok
//     Example.out_parameter(out n2); // ok

        // ref parameter 의 전달은 "초기화 된 것만 가능"
        Example.ref_parameter(ref n1); // error
        Example.ref_parameter(ref n2); // ok

        // out parameter 는 인자 전달 위치에서 변수를 생성할수도 있음
        int n3;     // 만들고
        Example.out_parameter(out n3); // 전달

        Example.out_parameter(out int n4); // 만들면서 전달
    }
}