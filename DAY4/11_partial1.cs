// partial 클래스
// => 하나의 클래스를 여러개 파일에 나누어서 작업하는 기술

// 왜 여러개 파일로 나누어서 작업하나요 ?

// 1. 메소드가 너무 많아서 "메소드 종류별로 나누어서 작업"
//    => string class

// 2. 하나의 클래스를 사람과 기계로 나누어서 코딩
//    => 내일 배우는 WPF 위저드 코드.. 
//    => UI 자체를 만드는 코드 - Visual Studio 가 자동 생성
//       UI Event 를 처리하는 코드 - 사람이 작성


partial class Window
{
    public void Show() 
    {
        Console.WriteLine("Window is shown");
    }   
}
class Program
{
    static void Main()
    {
        Window w = new Window();
        w.Show();

        string s;
    }
}