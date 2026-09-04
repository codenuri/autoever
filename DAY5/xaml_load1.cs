// xaml_load1.cs
// => WPF 기본 코드 복사해 오세요
using System.IO;
using System.Windows;
using System.Windows.Markup;
using System.Xaml.Permissions;

// 지금까지 예제
// => 모든 UI 를 C# 코드로 직접 작성

// 핵심 : UI 를 XML 로 만들어 봅시다

class MainFrame : Window
{
    public MainFrame()
    {
    }
}

class App : Application
{
    [STAThread]
    public static void Main()
    {
        App app = new App();


        // UI 를 만드는 XML 파일을 Load
        FileStream fs = new FileStream("..\\..\\..\\ex2.txt", FileMode.Open);

        Window win = (Window)XamlReader.Load(fs);

        win.Show();

        fs.Dispose();

        app.Run();
    }
}

// WPF 프로그램의 특징

// 모든 UI : XAML 을 사용해서 작성
//           XAML 조차도 자동생성해주는 프로그램이 있음.
//           따라서, 디자이너가 만들수 있다
//           자동생성된 파일에서는 확장자는 .xaml

// UI 에서 발생하는 이벤트 처리만 C# 코드로 작성
