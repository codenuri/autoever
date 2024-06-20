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

// 동일한 코드가 여러 클래스에서 사용되면 
// 기반 클래스를 만들어서 제공

class BaseDialog
{
public:
	void init()
	{
		IButton* btn = CreateButton();
		IEdit* edit = CreateEdit();

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
	// 객체를 만들기 위한 인터페이스를 정의하고 사용하지만
	// 어떤 종류(타입)의 객체를 만들지는 파생 클래스가 결정한다.
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit() = 0;
};


class WinDialog
{
public:

};

class OSXDialog
{
public:
	void init()
	{
		OSXButton* btn = new OSXButton;
		OSXEdit* edit = new OSXEdit;

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
};


int main(int argc, char** argv)
{

}








