// Python 의 함수 모양
// def add(x, y):
// 	   return x + y


// #1. C# 의 함수 모양
// => C/C++/Java 등 대부분의 언어의 공통된 모양
int add1(int a, int b)
{
    return a + b;
}
int n1 = add1(1, 2);


// #2. expression bodied
// => C# 에서는 간단한 함수를 보다 간결하게 구현하는 문법 제공
// => 아래 코드는 위 add1 과 동일 
// => 다른 언어에 없는 C# 만의 문법. 실전에서 많이 사용
int add2(int a, int b) => a + b;



// #3. 용어
// => 대부분 프로그래밍 언어에서 아래의 용어가 사용됩니다
// 메소드(method) : class 안에서 만드는 함수를 나타내는 용어
//                  인스턴스 메소드, 정적 메소드등
//                  "변수이름.이름()" 또는 "타입이름.이름()" 으로 호출
//                   "n1.ToString()"
//                  C++ 에서는 멤버 함수 라고 표현


// 함수(function) : class 와 상관없이 만드는 함수
//                  위 소스의 add1, add2 는 메소드가 아닌 함수


