using System.Windows;
using System.Windows.Controls;

// #1. DockPanel 사용하기

class MainWindow : Window
{
	public MainWindow() 
	{
        // #1. Panel 만들어서 윈도우에 부착
        DockPanel dp = new DockPanel();
        Content = dp;

        // #2. 컨트롤 생성
        Button btn1 = new Button { Content = "button1" };
        Button btn2 = new Button { Content = "button2" };
        Button btn3 = new Button { Content = "button3" };

        // #3. 각 컨트롤이 Dock 패널 어디에 놓일지 속성지정
        DockPanel.SetDock(btn1, Dock.Top);
        DockPanel.SetDock(btn2, Dock.Bottom);
        DockPanel.SetDock(btn3, Dock.Left);

        // #4. 각 컨트롤을 패널에 자식으로 추가
        dp.Children.Add(btn1);
        dp.Children.Add(btn2);
        dp.Children.Add(btn3);

    }
}


class App : Application
{
    [STAThread]
    public static void Main()
    {
		App app = new App();

        MainWindow w = new MainWindow();
        w.Title = "Hello, WPF";
        w.Show();
        
        app.Run();
    }
}