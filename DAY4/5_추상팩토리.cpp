// 3_추상팩토리 - 147
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

int main(int argc, char** argv)
{
	// 조건에 따라 다른 타입의 객체를 만들게 되므로
	// 두 타입의 공통의 기반 클래스(인터페이스)포인터 사용
	IButton* btn;

	if (strcmp(argv[1], "-style:OSX") == 0)
		btn = new OSXButton;
	else
		btn = new WinButton;

	// 그런데!! 
	// 프로그램에서 "UI 만드는 코드가 위 한줄만 있을까요 ???"
	// => 많은 UI를 만들어야 합니다.
	// => 스타일별 컨트롤을 만드는 공장이 필요합니다.
}








