using System.Media;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

// Sliding Puzzle Game #6. 
// => 마우스 왼쪽 버튼 클릭시 블럭 이동하기





class MainWindow : Window
{
    private const int CNT = 5;
    private const int EMPTY = CNT * CNT - 1;
    private double block_width;
    private double block_height;

    private Grid grid = null;


    private int[,] state = null;

    public void InitState()
    {
        state = new int[CNT, CNT];

        int k = 0;

        for (int y = 0; y < CNT; y++)
        {
            for (int x = 0; x < CNT; x++)
            {
                state[y, x] = y * CNT + x; // 0, 1, 2, 3, 4.... 
            }
        }
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
                if (state[y, x] == EMPTY)
                    continue;

                int bx = state[y, x] % CNT;
                int by = state[y, x] / CNT;


                Int32Rect rc = new Int32Rect((int)(bx * block_width),
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
        grid.MouseLeftButtonDown += Grid_MouseLeftButtonDown;
    }

    private void Grid_MouseLeftButtonDown(object sender, System.Windows.Input.MouseButtonEventArgs e)
    {
        Point pt = e.GetPosition(this);

        // #1. 좌표로 부터 어느 블럭을 클릭했는지 계산

        // block_width 가 100 이어도,
        // 윈도우 size 변경되면 실제 block 크기는 달라집니다
//      int bx = (int)(pt.X / block_width);
//      int by = (int)(pt.Y / block_height);

        int bx = (int)(pt.X / (grid.ActualWidth / CNT));
        int by = (int)(pt.Y / (grid.ActualHeight / CNT));


        Console.WriteLine("{0}, {1}", bx, by);

        // #2. 상/하/좌/우 에 EMPTY(24) 가 있는지 확인
        if (bx < CNT - 1 && state[by, bx + 1] == EMPTY)  // 오른쪽이 EMPTY
        {
            // (by, bx) <=> ( by, bx + 1)
            Swap(by, bx, by, bx + 1); // 2개 블럭 교환
        }
        else if (bx > 0  && state[by, bx - 1] == EMPTY)  // 왼쪽 EMPTY
        {
            Swap(by, bx, by, bx -1);
        }
        else if (by < CNT - 1 && state[by + 1, bx] == EMPTY)  // 아래 EMPTY
        {
            Swap(by, bx, by + 1 , bx);
        }
        else if (by > 0 && state[by - 1, bx] == EMPTY)  // 위 EMPTY
        {
            Swap(by, bx, by - 1, bx);
        }
        else
        {
            SystemSounds.Beep.Play(); // "삑"
        }
    }

    public void Swap(int y1, int x1, int y2, int x2)
    {
        // state 배열의 내용을 swap
        int temp = state[y1, x1];
        state[y1, x1] = state[y2, x2];
        state[y2, x2] = temp;


        // grid 안의 Image 얻기
        // => grid 의 0, 0 에 있는 자식(img)를 한번에 구하는 방법이 없습니다
        // => 그래서 GetImage() 함수 만든 것
        Image img1 = GetImage(y1, x1);
        Image img2 = GetImage(y2, x2);

        if (img1 != null)
        {
            Grid.SetRow(img1, y2);
            Grid.SetColumn(img1, x2);
        }
        if (img2 != null)
        {
            Grid.SetRow(img2, y1);
            Grid.SetColumn(img2, x1);
        }
    }

    // Grid에서 row, col 에 있는 Image 를 구하는 함수
    // => Grid 의 모든 요소를 순회 하면서 row, col 의 값을 조사한것
    public Image GetImage(int y1, int x1)
    {
        foreach (UIElement e in grid.Children)
        {
            if (Grid.GetRow(e) == y1 && Grid.GetColumn(e) == x1)
                return (Image)e;
        }
        return null;
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