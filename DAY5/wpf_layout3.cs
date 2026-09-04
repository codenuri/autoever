using System.Windows;
using System.Windows.Controls;

// Grid Layout
// => 가로세로 격자 모양으로 관리

class MainWindow : Window
{
    public MainWindow()
    {
        // #1. Grid 객체 생성
        Grid grid = new Grid();
        Content = grid;

        // #2. grid 의 row 와 column 은 몇개인가 ?
        grid.Row = 2;
        grid.Column = 2;
 
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