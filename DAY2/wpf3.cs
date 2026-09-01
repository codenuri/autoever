using System.Windows;

// 핵심 : Window 클래스로 GUI 만들기

class Program
{
    public static void Main()
    {
        Window w = new Window();

        w.Show();

        MessageBox.Show("Hello, WPF");
    }
}