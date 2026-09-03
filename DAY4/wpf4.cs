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


        Button btn = new Button { Content = "확인" };
        Content = btn;

        // 핵심 : 버튼의 이벤트 처리
        btn.Click += ButtonClick;
    }
    private void ButtonClick(object sender, RoutedEventArgs e)
    {
        Console.WriteLine("Button Click");
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
