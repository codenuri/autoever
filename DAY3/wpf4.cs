using System.Windows;
using System.Windows.Input;

// 아래 소스가 WPF 프로그램의 핵심 기본 코드 입니다.
// => 이제 각 클래스 안에서 약속된 가상함수는 override 해서 기능을 구현하면됩니다.
class MainFrame : Window
{
    // 주로 GUI 이벤트 처리를 위한 가상함수 override
}

class App : Application
{
    // 프로그램 시작, 종료, 배터리 부족,등의 시점에서 해야할 다양한 작업을 위해
    // 가상함수 override

    [STAThread]
    public static void Main()
    {
        MainFrame w = new MainFrame();
        w.Show();

        App app = new App();
        app.Run();
    }

}
