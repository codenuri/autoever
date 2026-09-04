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
        Button btn1 = new Button { Content = "확인" };
        Button btn2 = new Button { Content = "취소" };
        TextBox txtbox = new TextBox();

        StackPanel sp = new StackPanel();


        // #3. 각 컨트롤이 Dock 패널 어디에 놓일지 속성지정

        DockPanel.SetDock(txtbox, Dock.Top);
        DockPanel.SetDock(sp, Dock.Bottom); // 핵심 : 패널의 중첩


        // #4. 각 컨트롤을 패널에 자식으로 추가
       
        dp.Children.Add(sp);
        dp.Children.Add(txtbox); // 핵심. 마지막에 붙인 자식이 나머지 전체 사용

        // 버튼은 stack panel 이 자식으로 

        sp.Orientation = Orientation.Horizontal;
        sp.HorizontalAlignment = HorizontalAlignment.Right;

        btn1.Width = 100;
        btn1.Height = 50;
        btn1.Margin = new Thickness(5);

        btn2.Width = 100;
        btn2.Height = 50;
        btn2.Margin = new Thickness(5);

        sp.Children.Add(btn1);
        sp.Children.Add(btn2);

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