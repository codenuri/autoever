using System.Windows;
using System.Windows.Controls;

// #4. 버튼 같은 GUI 의 이벤트 처리하기
// => delegate(event) 방식으로 되어 있음
// => 특정 이벤트 발생시 호출될 함수를 등록하는 방식

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
