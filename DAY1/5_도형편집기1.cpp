#include <iostream>
#include <vector>

// 파워 포인트 같은 프로그램을 "객체지향 설계"로 만드는 것을
// 생각해 봅시다.

// 1. 모든 도형을 타입으로 설계하면 편리하다.

class Rect
{
//	int x, y, w, h;  생성자등은 생략
public:
	void draw() { std::cout << "draw Rect\n"; }
};


int main()
{

}

