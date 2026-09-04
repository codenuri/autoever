using System.Windows;
using System.Windows.Controls;

// Sliding Puzzle Game #1
// => 화면에 그림 출력하기

class MainWindow : Window
{
    public MainWindow()
    {
        // #1. 자원의 위치를 관리하는 객체 생성
        Uri uri = new Uri("..\\..\\..\\totoro.jpg"); // 여러분의 그림파일이름

        // #2. 그림을 메모리에 Load
        BitmapImage bitmap = new BitmapImage(uri);

        // #3. bitmap 안에 있는 그림을 화면에 그릴때 사용하는 Image 객체 생성
        Image img = new Image();
        img.Source = bitmap;

        // #4. Image 객체를 MainWindow Content 로 연결
        Content = img;
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