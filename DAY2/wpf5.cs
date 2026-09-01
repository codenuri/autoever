using System.Windows;
using System.Windows.Media;

class Program
{
    [STAThread]
    public static void Main()
    {
        /*
        Window w = new Window();

        w.Title = "Hello";
        w.Width = 200;
        w.Height = 200;
        w.Background = new SolidColorBrush(Colors.Yellow);
        */

        // 아래 코드 배운 문법입니다. 이해해 보세요
        Window w = new Window { Title = "Hello", Width = 200, Height = 200 };


        w.Show();


        Application app = new Application();
        app.Run();

    }
}