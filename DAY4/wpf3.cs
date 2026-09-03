using System.Windows;
using System.Windows.Controls;

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

        // #1. Content 에 문자열 연결
//      Content = "ABCD"; // <== 핵심

        // #2. Content 에 버튼 연결
        Button btn = new Button();
        btn.Content = "확인";

        Content = btn;
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
