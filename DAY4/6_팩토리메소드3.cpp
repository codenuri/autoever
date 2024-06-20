// 5_팩토리메소드
#include <iostream>

// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//--------------------------------------

// C++은 Factory method 보다는 "template 기법"이 더 널리 사용됩니다.
// 
// 각 스타일별 "컨트롤의 클래스이름" 을 관리하는 구조체 설계
struct Windows
{
	using Button = WinButton;
	using Edit   = WinEdit;
	// 모든 컨트롤의 이름을 이곳에서 보관
};
struct OSX
{
	using Button = OSXButton;
	using Edit = OSXEdit;	
};

template<typename Style>
class Dialog
{
public:
	void init()
	{
//		IButton* btn = new Style::Button;  // 컴파일 에러. 컴파일러 "Style::Button" 을 
											// 타입이 아닌 static 멤버로 취급

		IButton* btn = new typename Style::Button;
		IEdit*  edit = new typename Style::Edit;

		btn->Draw();
		edit->Draw();
	}
};






int main(int argc, char** argv)
{
	Dialog<OSX>     dlg1;
	Dialog<Windows> dlg2;
}








