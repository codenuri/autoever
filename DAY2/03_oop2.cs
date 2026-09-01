using static System.Console;

// class 키워드
// => 새로운 타입을 만들때 사용하는 키워드

class Rect
{
    // 사각형 한개의 정보를 보관할 데이터
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    // 사각형에 관련된 기능을 제공하는 함수 
    int GetRectArea()
    {
        return (x2 - x1) * (y2 - y1);
    }
}

// Rect 타입이 없을때 사용자 코드
// int area = GetRectArea(1, 1, 10, 10);

// Rect 라는 타입이 있으면 사용자는 아래 처럼 사용하게 됩니다.
Rect rc = new Rect();
int area = rc.GetRectArea();