using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

// Sliding Puzzle Game #3
// => Grid 도입

// puzzle2.cs
// => 윈도우.Content = 한블럭;   <= 윈도우 전체에 한블럭만 표현

// 아래 소스
// => 윈도우.Content = grid;
// => grid 의 0, 0 에 1번째 블럭 표기


class MainWindow : Window
{
    private const int CNT = 5;               
    private const int EMPTY = CNT * CNT - 1; 
    private double block_width;
    private double block_height;



    public MainWindow()
    {
        Uri uri = new Uri("..\\..\\..\\totoro.jpg", UriKind.Relative);

        BitmapImage bitmap = new BitmapImage(uri);

        block_width = bitmap.Width / CNT;
        block_height = bitmap.Height / CNT;

        Int32Rect rc = new Int32Rect(0, 0, (int)block_width, (int)block_height);
        CroppedBitmap crop = new CroppedBitmap(bitmap, rc);

        Image img = new Image();
        img.Source = crop; // <==
        img.Stretch = Stretch.Fill;


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