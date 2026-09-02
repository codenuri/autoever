using System.Windows;
using System.Windows.Input;

class MainFrame : Window
{
    protected override void OnMouseLeftButtonDown(MouseButtonEventArgs e)
    {
        Point pt = e.GetPosition(this);    

        Console.WriteLine("LButtonDown : {0}, {1}", pt.X, pt.Y);
    }

    protected override void OnMouseRightButtonDown(MouseButtonEventArgs e)
    {
        Console.WriteLine("RButtonDown");
    }
}

// WPF 의 핵심 클래스 2개
// Window : 윈도우 창(GUI) 를 만들기 위해서 제공
//          => 보통 파생 클래스 만들어서 사용
//          => 가상함수 override 해서 event 처리를 하기 위해 파생 클래스 만든것

// Application : GUI 아님. 프로그램시작, 종료, 이벤트 루프등을 담당
//          => 보통 파생 클래스를 만들어서 사용

class App : Application
{
    protected override void OnStartup(StartupEventArgs e)
    {
        Console.WriteLine("OnStartup : 프로그램 시작시 호출. 여기서 로고 보여주세요");
    }

    protected override void OnExit(ExitEventArgs e)
    {
        Console.WriteLine("OnExit : 프로그램 종료 직전 호출. 여기서 사용한 자원정리");
    }
}


class Program
{
    [STAThread]
    public static void Main()
    {
        MainFrame w = new MainFrame();
        w.Show();

        Application app = new Application();
        app.Run();
    }
}
