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
//-----------------

// 추상 팩토리 패턴(abstract factory)
// => 제품의 군을 만들기 위한 인터페이스를 제공한다.
// => 공장도 인터페이스를 먼저 만들고, 교체 가능하도록 하자는 것

// => 디자인 패턴 23개 분류에서 "Factory" 라는 패턴은 없습니다.
// => "abstract factory" 가 있습니다

struct IFactory
{
	virtual IButton* CreateButton() = 0;
	virtual IEdit* CreateEdit() = 0;

	// Button, Edit 외에도 수십개의 GUI 컨트롤을 생성하는 함수들.. 

	virtual ~IFactory() {}
};


//  style 별로 각 콘트롤을 만드는 공장
class WinFactory 
{
public:
	IButton* CreateButton() { return new WinButton; }
	IEdit*   CreateEdit()   { return new WinEdit; }
	virtual ~WinFactory() {}
};

class OSXFactory 
{
public:
	IButton* CreateButton() { return new OSXButton; }
	IEdit*   CreateEdit() { return new OSXEdit; }
	virtual ~OSXFactory() {}
};


int main(int argc, char** argv)
{
	IFactory* factory;

	if (strcmp(argv[1], "-style:OSX") == 0)
		factory = new OSXFactory;
	else
		factory = new WinFactory;


	// 컨트롤이 필요하면 공장을 사용해서 생성
	IButton* btn = factory->CreateButton();
	btn->Draw();
}











