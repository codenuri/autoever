using System.Windows;

// #3. Content 속성
// => WPF 핵심
// => 모든 UI 는 자신의 Content 에 지정된 요소를 적절한 방식으로 보여준다

class MainFrame : Window
{
    public MainFrame()
    {
        Title = "Hello, WPF";    
        Width = 300;
        Height = 600;

        Content = "ABCD"; // <== 핵심
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
