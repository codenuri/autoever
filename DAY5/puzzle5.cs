using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

// Sliding Puzzle Game #5. 상태를 나타내는 2차원 배열 도입
// => 다양한 종류의 게임 프로그램에서 공통으로 사용하는 핵심 개념





class MainWindow : Window
{
    private const int CNT = 5;
    private const int EMPTY = CNT * CNT - 1;
    private double block_width;
    private double block_height;

    private Grid grid = null;


    // 게임판의 상태를 나타내는 2차원 배열
    private int[,] state = null;

    public void InitState()
    {
        state = new int[CNT, CNT];

        int k = 0;

        for(int y = 0; y < CNT;y++)
        {
            for (int x = 0; x < CNT; x++)
            {
                state[y, x] = y * CNT + x; // 0, 1, 2, 3, 4.... 
            }
        }

        state[0, 3] = 0; // 테스트용 코드
    }





    public void InitGrid()
    {
        grid = new Grid();
        Content = grid;

        for (int i = 0; i < CNT; i++)
        {
            grid.RowDefinitions.Add(new RowDefinition());
            grid.ColumnDefinitions.Add(new ColumnDefinition());
        }
    }

    public MainWindow()
    {
        InitGrid();
        InitState();

        Uri uri = new Uri("..\\..\\..\\totoro.jpg", UriKind.Relative);

        BitmapImage bitmap = new BitmapImage(uri);

        block_width = bitmap.Width / CNT;
        block_height = bitmap.Height / CNT;


        for (int y = 0; y < CNT; y++)
        {
            for (int x = 0; x < CNT; x++)
            {
                // 핵심
                // => 8 번 블럭을 그리려면 x 축으로 3, y 축으로 1을 알아야 합니다
                int bx = state[y, x] % CNT; // x축  8 % 5 => 3
                int by = state[y, x] / CNT; // y축  8 / 5 => 1


                Int32Rect rc = new Int32Rect( (int)(bx * block_width),
                                              (int)(by * block_height),
                                              (int)block_width,
                                              (int)block_height);

                CroppedBitmap crop = new CroppedBitmap(bitmap, rc);

                Image img = new Image();
                img.Source = crop; // <==
                img.Stretch = Stretch.Fill;
                img.Margin = new Thickness(0.5);

                Grid.SetRow(img, y);
                Grid.SetColumn(img, x);

                grid.Children.Add(img);


            }
        }


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