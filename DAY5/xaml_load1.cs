// xaml_load1.cs
// => WPF 기본 코드 복사해 오세요
using System.IO;
using System.Windows;
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
        FileStream fs = new FileStream("..\\..\\..\\ex1.txt", FileMode.Open);

        Window win = (Window)XamlReader.Load(fs);

        win.Show();

        fs.Dispose();

        app.Run();
    }
}