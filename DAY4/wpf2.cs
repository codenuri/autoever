using System.Windows;

// #2. MainFrame 에서 자신의 속성 설정 자신의 메소드안에서 하는 것이 좋다

class MainFrame : Window
{
    public MainFrame()
    {
        // 윈도우 생성시 자신을 초기화
        // 즉, 다양한 속성을 여기서 설정
        // this.Title = "Hello, WPF";
        Title = "Hello, WPF";    // this 를 생략해도 컴파일러가 추가
        Width = 300;
        Height = 600;
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
