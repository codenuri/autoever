using System.Windows;

// 핵심 : Window 클래스로 GUI 만들기

class Program
{    
    [STAThread]     // Main 함수에서 GUI 만들때 필요. 관례적 코드. 항상동일
    public static void Main()
    {
        Window w = new Window();

        w.Show();

        // 아래 코드가 없으면 프로그램은 즉시 종료되므로
        // 윈도우가 바로 파괴 되고 종료 됩니다.
//      MessageBox.Show("Hello, WPF");
    }
}