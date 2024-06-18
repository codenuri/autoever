// Edit 예제 정리 - 교재 33 ~ 

// Edit2.cpp
// => 변하는 것(validation 정책) 을 가상함수로 분리
// => 상속을 사용하는 패턴!!
// => template method 패턴.
// 특징 : Validation 정책을 NumEdit 가 소유하게 된다.

// 1. 다른 입력컨트롤에서 Validation 정책 사용하기 어렵다.
//    정책을 NumEdit 가 소유(멤버 함수)하므로
// 
// 2. Edit 가 실행시간에 Validation 정책을 교체 할수 없다.

// 3. Valiation 정책 NumEdit 의 멤버 함수 이므로
//    Edit 의 멤버에 접근하기 쉽다.





// Edit3.cpp
// => 변하는 것(validation 정책) 을 다른 클래스로 분리
// => Strategy(전략) 패턴
// 특징 : Validation 정책이 다른 클래스로 분리되어 있다
// 
// 1. 다른 입력컨트롤에서도 다양한 Validation 정책 사용가능
//    Validation 정책에 Edit 와는 별개의 클래스로 되어 있으므로!!
// 
// 2. Edit 가 실행시간에 Validation 정책을 교체 할수 있다.

// 3. Valiation 정책이 다른 클래스로 분리되어 있으므로 
//    Edit 의 멤버 데이타 접근이 어렵다.!!

// MFC 라이브러리의 CEdit : Edit2.cpp 로 디자인되어 있습니다.
// QT  라이브러리의 QEdit : Edit3.cpp 로 디자인되어 있습니다. (QValidator 있습니다)

// 도형편집기를 생각해 봅시다.
// => draw/draw_imp
class Shape
{
protected:
	virtual void draw_imp() = 0;
public:
	void draw()
	{
		std::cout << "mutex lock\n";
		draw_imp();
		std::cout << "mutex unlock\n";
	}
};

class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw Rect\n"; }
};
// 도형을 그리는 정책은
// 1. 실행시간에 변경할 필요가 없고..
// 2. 사각형을 그리는 정책을 다른 클래스에 사용할 필요도 없고
// 3. 그림을 그리려면 멤버 데이타에 접근해야 합니다.
// 
// 즉 도형 편집기 예제는 : strategy 보다 template method 가 좋습니다.
// Edit 예제는          : template method 보다 strategy 가 좋습니다.