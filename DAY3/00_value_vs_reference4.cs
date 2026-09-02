using static System.Console;

// C# 의 모든 타입은 아래 2가지로 분류 됩니다.

// 1. Reference Type
// => 객체 자체는 힙에 생성되고
// => 스택에 있는 레퍼런스 변수가 힙의 객체를 가리키는 것(포인터)
// => 교재 36 page 그림
// => class 키워드를 사용해서 만드는 타입

// 2. Value Type
// => 객체 자체가 Stack 에 생성된것
// => struct 키워드를 사용해서 만드는 타입

// [참고] 파이썬은 모든 변수가 Reference Type 인것
// n = 3  : 3 은 힙에 생성. stack 에 있는 n 이 3의 주소를 가지고 있는것


// 우리가 만드는 타입(Date) 를 Reference Type(class) 로 할것인가 ?
// Value Type(struct) 로 할것인가 ?
// => 쉽지 않다.
// => 많은 지식과 경험이 필요 하다


// 그런데, 우리가 만드는 것이 아니라
// 표준이 제공해서 사용하는 타입들이 Reference Type 인지 ? Value Type 인지 ?
// 는 반드시 알아야 제대로 사용할수 있다
// => 초보자도 필수
//-----------------------------------------------------------------

// 핵심 : 어떤 타입이 "value type" 인지 "reference type"
//        인지를 정확히 알아야 한다.
// => 아래 코드들의 메모리 그림을 이해해야 합니다

// #1. int, double 등의 기본 수치 타입
// => Value Type

int n1 = 10;
int n2 = n1;    // Reference Type 이면 : 참조(주소) 복사
                // Value Type 이면     : 값(10) 복사 <= int 는 이 경우

n1 = 20;
WriteLine($"{n1} {n2}");    // Reference Type 이면 : 20, 20
                            // Value Type     이면 : 20  10	<= int 는 이경우
//-------------------------------------------------------------------------
// #2. 배열
// => 복습할때 아래 코드를 "Reference Type 일때 Value Type" 일때 꼭 그려보세요
// => Reference Type
// => 참고 : Swift 언어는 배열이 Value Type 입니다.
int[] x1 = {1, 2, 3};
int[] x2 = x1;

x1[0] = 20;

WriteLine($"{x1[0]} {x2[0]}");	// Reference Type 였다면 : 20, 20
                                // Value Type 이었다면   : 20, 1
// #3. string 타입
// => 아래 코드를 실행결과를 확인하세요
// => 결과를 보고 Value Type 인지 ? Reference 인지 예상해 보세요
// => Reference Type 입니다.
// => 그런데, 실행결과를 보면 Value Type 처럼 보입니다.
// => String 의특징을 알아야 정확히 이해 할수 있습니다.

string s1 = "AB";
string s2 = s1;

s1 = "XY";

WriteLine($"{s1} {s2}");   // "XY", "AB"
// 아래 주석은 잘못된것
// Reference 라면 : "XY", "XY"
// Value 라면     : "XY", "AB"