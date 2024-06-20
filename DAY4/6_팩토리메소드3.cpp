// 5_���丮�޼ҵ�
#include <iostream>

// ��� ������ ��Ʈ���� ������ ��� Ŭ���� �ʿ�
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

// C++�� Factory method ���ٴ� "template ���"�� �� �θ� ���˴ϴ�.
// 
// �� ��Ÿ�Ϻ� "��Ʈ���� Ŭ�����̸�" �� �����ϴ� ����ü ����
struct Windows
{
	using Button = WinButton;
	using Edit   = WinEdit;
	// ��� ��Ʈ���� �̸��� �̰����� ����
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
//		IButton* btn = new Style::Button;  // ������ ����. �����Ϸ� "Style::Button" �� 
											// Ÿ���� �ƴ� static ����� ���

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








