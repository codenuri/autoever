//this1.cs 


// #1. 필드는 객체당 한개씩 메모리에 생성됩니다.
// => Point 객체를 2개 생성하면, x, y 도 각각 2개씩 존재합니다.

// #2. 객체를 여러개 생성해도 메소드는 코드메모리에 한개만 존재
// => 모든 객체가 한개만 있는 메소드를 같이 사용하는 것

using System.Runtime.CompilerServices;
using System.Runtime.InteropServices.Swift;

class Point
{
    private int x = 0;
    private int y = 0;

    // this : 메소드 안에서 자신을 호출할때 사용한 객체를 나타내는 키워드

    // 사용자가 만든 코드               // 컴파일러가 변경한 코드
    public void Set(int a, int b)      // void Set(Point this, int a, int b)
    {                                  // { 
        x = a;                         //      this.x = a;
        y = b;                         //      this.y = b;
    }                                  // }
}
class Program
{
    public static void Main()
    {
        Point p1 = new Point();
        Point p2 = new Point();

        // 사용자가 만든 코드        // 컴파일러가 변경하는 코드
        p1.Set(1, 2);               // Set(p1, 1, 2)
        p2.Set(1, 2);               // Set(p2, 1, 2)
    }
}

// 파이썬
/*
class Point:
    def set(self, a, b):
        self.x = a
        self.y = b 

pt = Point()
pt.set(1, 2) // set(pt, 1, 2) 로 변경됨

// C++/C#/Java/Swift 
// => 객체를 전달 받는 코드를 컴파일러가 추가
void Set(int a, int b) ===> void Set(Point this, int a, int b)

// Python/Rust 
// => 개발자가 직접 코드에 표현
def set(self, a, b):
*/
