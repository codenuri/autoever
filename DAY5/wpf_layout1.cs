using System.Windows;
using System.Windows.Controls;

// #1. DockPanel 사용하기
// => 자식 컨트롤을 "Top, Bottom, Left, Right" 에 부착
// => 마지막 붙인 자식이 나머지 영역 전체를 사용

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
        // => 아직 자식 콘트롤로 등록된것은 아니고
        // => 자식이 될때 어느위치에 들어갈지만 먼저 세팅
        // => DockPanel 의 정적 메소드 사용
        DockPanel.SetDock(btn1, Dock.Top);
        DockPanel.SetDock(btn2, Dock.Bottom);
        DockPanel.SetDock(btn3, Dock.Left);

        // #4. 각 컨트롤을 패널에 자식으로 추가
        dp.Children.Add(btn1);
        dp.Children.Add(btn3);
        dp.Children.Add(btn2); // <= 마지막 자식이 나머지 영역  전체 사용

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