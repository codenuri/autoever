using static System.Console;

class Button
{
	// 사용자가 버튼을 누르면 아래 함수가 호출된다고 가정
	public void UserPressButton()
	{
		// 버튼 누를때 여기서 직접 작업을 수행하면
		// 여러개 버튼이 동일한 일을 하게 됩니다.

		// 여기서 등록된 함수를 호출하게 만들어야 합니다.
	}
}

class Program
{
	public static void Main()
	{
		Button btn1 = new Button(); // 이순간 GUI 버튼이 만들어 지고
		Button btn2 = new Button();
	
		btn1.UserPressButton(); // 사용자가 버튼을 누르면
		btn2.UserPressButton(); // 이 메소드가 호출된다고 가정. 		
	}
}