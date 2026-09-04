using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

// Sliding Puzzle Game #1
// => 화면에 그림 출력하기

class MainWindow : Window
{
    public MainWindow()
    {
        // #1. 자원의 위치를 관리하는 객체 생성
        // => Universal Resource Identify
        // => 그림파일을 현재 프로젝트 폴더(DAY5)에 놓으세요
        Uri uri = new Uri("..\\..\\..\\totoro.jpg", UriKind.Relative); 

        // #2. 그림을 메모리에 Load
        BitmapImage bitmap = new BitmapImage(uri);

        // #3. bitmap 안에 있는 그림을 화면에 그릴때 사용하는 Image 객체 생성
        // BitmapImage : 그림 데이터 자체의 관리
        // Image       : BitmapImage 가 관리하는 데이터를 화면 출력
        // => 역활을 분리한것
        Image img = new Image();
        img.Source = bitmap;
        img.Stretch = Stretch.Fill;

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