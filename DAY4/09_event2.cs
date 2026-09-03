using static System.Console;


// Handler : 함수 호출 정보를 보관하는 타입
delegate void Handler();

class Button
{
    public Handler handler = null;

    public void UserPressButton()
    {
        // 버튼을 누르면 등록된 함수를 호출
        if ( handler != null)
        {
            handler();
        }
    }
}

class Program
{
    public static void Main()
    {
        Button btn1 = new Button(); 
        Button btn2 = new Button();

        btn1.handler = Foo;
        btn2.handler = Goo;

        btn1.UserPressButton(); 
        btn2.UserPressButton(); 		
    }
    public static void Foo() => WriteLine("button1 click");
    public static void Goo() => WriteLine("button1 click");
}