// wpf1.cs

// WPF 사용하려면 
// 1. "콘솔앱" 프로젝트로 만드세요
// 2. "프로젝트 설정 파일" 에서 2개만 변경하세요
//    => <TargetFramework>net10.0-windows</TargetFramework> 변경
//    => <UseWPF>true</UseWPF>  추가

// 3. 아래 코드 작성하세요
using System.Windows;

class Program
{
    [STAThread] // 무조건 표기. 관례적인 코드
    public static void Main()
    {
        // GUI 만들기
        Window w = new Window();
        w.Show();

        // 종료되지 말고 계속 루프를 수행하면서
        // GUI 에서 발생하는 event 들을 처리
        Application app = new Application();
        app.Run();
    }
}
