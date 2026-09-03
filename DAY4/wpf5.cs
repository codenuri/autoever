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

//      sp.Orientation = Orientation.Horizontal;

        // #2. 윈도우의 Content 로 sp 연결
        Content = sp;

        // #3. 이제 Layout 위에 다양한 컨트롤 연결
        //      sp.Children.Add(new Button { Content = "button1" });
        //      sp.Children.Add(new Button { Content = "button2" });
        //      sp.Children.Add(new Button { Content = "button3" });

        Button btn1 = new Button { Content = "button1" };
        Button btn2 = new Button { Content = "button1" };
        Button btn3 = new Button { Content = "button1" };

        sp.Children.Add(btn1);
        sp.Children.Add(btn2);
        sp.Children.Add(btn3);

        // btn1, btn2 등의 변수가 있으므로 해당 변수에 다양한 추가 작업가능

        btn1.Click += Btn1_Click;
    }

    private void Btn1_Click(object sender, RoutedEventArgs e)
    {
        Console.WriteLine("button1 click");
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
