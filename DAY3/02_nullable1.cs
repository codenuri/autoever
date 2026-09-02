using static System.Console;

// Reference Type 의 변수
// => 객체의 주소를 보관하는 변수
// => C 언어의 포인터


// #1. reference type 의 변수는 null 로 초기화 될수 있습니다.
string s1 = "hello";
string s2 = null; // ok. 힙에 객체 없음을 의미.	


// #2.value type 의 변수는 null 로 초기화  될수 없습니다.
int n1 = 0;
int n2 = null;  // error. n2 는 주소를 보관하는 변수가 아닌
                //        정수값을 보관하는 변수


// #3. C# 2.0 만들때 Value Type 도 값없음(null) 을 지원하고 싶었습니다.

Nullable<int> n3 = null; // null 보관이 가능한 int 타입
int? n4 = null;          // int? 이 Nullable<int> 에대한 단축 표기
                         // n4 는 n3 과 동일

// 정리
int  n5 = null; // error. null 될수 없다. 
int? n6 = null; // ok.    null 될수 있다

// #4. int? 의 원리 - 교재 55 page 그림
// => "Nullable 의 정의" 확인해 보세요

struct Nullable<int>
{
    private bool hasValue; // 값 있음/없음 관리
    private int value;     // 값이 있을때의 값 저장
}

