// wpf1.cs

using System.Windows;

class MainFrame : Window
{
}
class App : Application
{
    [STAThread]
    public static void Main()
    {
        MainFrame w = new MainFrame();
        w.Title = "Hello, WPF";

        App app = new App();
        app.Run();
    }
}
