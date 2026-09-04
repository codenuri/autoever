using System.Windows;
using System.Windows.Controls;

// Sliding Puzzle Game #1
// => 화면에 그림 출력하기

class MainWindow : Window
{
    public MainWindow()
    {
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