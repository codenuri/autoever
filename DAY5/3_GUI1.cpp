// 32bit 환경에서 빌드해야 합니다.
// => "X86" 으로 빌드
#define USING_GUI
#include "cppmaster.h"

// GUI 프로그램을 개발하려면
// => 각 OS 가 C 언어 기반으로 GUI 관련 함수를 제공하고 있습니다.
// => 해당 함수를 사용하면 됩니다. 

// 아래 코드는 
// => C 언어를 사용해서 GUI 프로그램을 만든 예제..!!
// => C 언어를 직접 사용하면 항상 복잡한 형태가 됩니다.
// => 다음 예제 부터, 객체지향 라이브러리로 설계해 봅시다.


// 윈도우 이벤트를 처리하는 함수는 반드시 인자가 4개 이어야 합니다.
int msgproc(int hwnd, int msg, int a, int b) 
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON : " << hwnd << std::endl; break;
	case WM_KEYDOWN:     std::cout << "KEYDOWN : " << hwnd << std::endl; break;
	}
	return 0;
}

int main()
{
	int h1 = ec_make_window(msgproc, // 윈도우에서 발생된 이벤트를 처리할함수
							"A");
	int h2 = ec_make_window(msgproc, "B");


	// 자식윈도우 만들기
	ec_add_child(h1, h2); // h2 를 h1 의 자식윈도우로 만들기.


	ec_process_message();	// 프로그램을 종료 하지 말고
							// window 에서 발생하는 이벤트를 
							// 꺼내서, 등록된 함수에 전달해 달라
}

