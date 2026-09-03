using System.Windows;
using System.Windows.Controls;


class MainFrame : Window
{
    // #1. 필요한 컨트롤을 모두 필드로 선언
    private TextBox txtbox = null;
    private Button button = null;
    private Slider slider = null;

    public MainFrame()
    {
        // #2. 필요한 Layout 을 만들고 메인윈도우에 부착
        StackPanel sp = new StackPanel();
        Content = sp;

        // #3. 각 컨트롤 객체를 생성후, 기본 속성 설정, Layout 자식으로 등록
        txtbox = new TextBox();
        button = new Button { Content = "확인" };
        slider = new Slider { Minimum = 20, Maximum = 100 }; // 20 ~ 100

        sp.Children.Add(txtbox);
        sp.Children.Add(button);
        sp.Children.Add(slider);

        // #4. 컨트롤 이벤트를 처리하기 위한 함수 연결
        // 1. 버튼 누르면 txtbox 에 입력된 값 꺼내서 출력해 보세요
        // 2. slider 움직이면 txtbox 폰트 크기를 키우세요

        button.Click += Button_Click;

        slider.ValueChanged += Slider_ValueChanged;
    }

    private void Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
    {
        // 1. slider 의 현재 값 구하기
        double val = slider.Value;

        // 2. txtbox 의 폰트 크기 변경
        txtbox.FontSize = val;
    }


    private void Button_Click(object sender, RoutedEventArgs e)
    {
        string s = txtbox.Text;
        Console.WriteLine(s);

        txtbox.Text = ""; // 비우기
    }
}


class App : Application
{
    [STAThread]
    public static void Main()
    {
        MainFrame w = new MainFrame();
        w.Show();

        App app = new App();
        app.Run();
    }
}
