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

        App app = new App();
        app.Run();
    }
}
