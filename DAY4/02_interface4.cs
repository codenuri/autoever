using static System.Console;

// 사용자가 만든 클래스(타입)
// CompareTo() 메소드를 제공하고 싶다
// 1. 그냥 CompareTo() 메소드만 제공하는 방법
// 2. IComparable 인터페이스를 구현하겠다고 표기하는 방법

class Label 
{
	private string title;	
	public Label(string s) => title = s;

	public int CompareTo(Lable other)
	{
		// title 자체가 string 이므로 CompareTo 제공
		return title.CompareTo(other.title);
	}
}




class Program 
{
	public static void Main()
	{
		Label d1 = new Label("GOOD");
		Label d2 = new Label("BAD");

		// 사용자 정의 타입인 Label 도 크기 비교가 되도록 해봅시다.
		int ret = d1.compare_to(d2);
	}
}

