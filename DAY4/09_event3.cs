using static System.Console;


// Handler : 함수 호출 정보를 보관하는 타입
delegate void Handler();

class Button
{
    // 함수 등록시 =, +=, -= 이 3가지 연산자 모두 사용가능
//  public Handler handler = null;

    // 함수 등록시 = 안됨. +=, -= 만 가능
    public event Handler handler = null;

    public void UserPressButton()
    {
        // 버튼을 누르면 등록된 함수를 호출
        if (handler != null)
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

        // 버튼을 누를때 여러개 핸들러를 등록하고 싶었다
//     btn1.handler = Foo;
//     btn1.handler = Goo; // 실수로 += 대신 = 를 사용했다
                            // 이전 등록 함수 Foo 가 제거되고 Goo 만등록


        // event 를 표기한 경우 +=, -= 만 가능
        btn1.handler += Foo;
        btn1.handler += Goo;

        btn1.UserPressButton(); 
    }
    public static void Foo() => WriteLine("button1 click");
    public static void Goo() => WriteLine("button2 click");
}