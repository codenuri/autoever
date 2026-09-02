using System.Windows;
using System.Windows.Input;

// WPF 라이브러리 내부
/*
class Window
{
    public Window() {  생성자에서 윈도우 생성 }
    public void Show() {  윈도우 보여주기 }

    // 이 클래스로 생성된 윈도우에서 마우스 왼쪽 버튼을 누르면 아래 메소드가 호출되도록
    // 약속되어 있습니다.
    public virtual void OnMouseLeftButtonDown(...) { } 
}
*/
// 실전에서는 "Window" 클래스를 직접 사용하지 않고
// 파생 클래스를 만들어 사용하게 됩니다.
// => 파생 클래스 이름은 마음대로 정하면 됩니다.
class MainFrame : Window
{
    protected override void OnMouseLeftButtonDown(MouseButtonEventArgs e)
    {
        Console.WriteLine("LButtonDown");
    }
}



class Program
{
    [STAThread]
    public static void Main()
    {
//      Window w = new Window();
        MainFrame w = new MainFrame();
        w.Show();

        Application app = new Application();
        app.Run();
    }
}
