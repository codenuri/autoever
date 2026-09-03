using System.Windows;
using System.Windows.Controls;

// #5. Layout 개념
// => Content 속성에는 "한개 객체만 연결" 가능

class MainFrame : Window
{
    public MainFrame()
    {
        Title = "Hello, WPF";
        Width = 300;
        Height = 600;

        // #1. Layout 생성
        StackPanel sp = new StackPanel();

        // #2. 윈도우의 Content 로 sp 연결
        Content = sp;

        // #3. 이제 Layout 위에 다양한 컨트롤 연결
        sp.Children.Add(new Button { Content = "button1" });
        sp.Children.Add(new Button { Content = "button2" });
        sp.Children.Add(new Button { Content = "button3" });
    }
}


class App : Application
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
