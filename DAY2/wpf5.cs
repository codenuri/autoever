using System.Windows;

class Program
{
    [STAThread]
    public static void Main()
    {
        Window w = new Window();

        w.Show();

        // 프로그램에서 GUI 를 만든경우
        // => 프로그램을 종료하지 말고
        // => GUI 에서 발생하는 이벤트를 처리해야 합니다.

        Application app = new Application();
        app.Run();

    }
}