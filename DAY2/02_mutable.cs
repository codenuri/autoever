// mutable.cs

// 변수와 객체
// 객체 : 메모리에 만들어지는 모든 것을 부르는 용어
//        결국 변수도 객체 입니다.

// "객체의 상태를 변경" 을 
// "변수의 상태를 변경" 으로 생각하면 됩니다.



// 모든 프로그래밍 언어의 공통된 개념
// mutable   : 객체의 상태를 변경할수 있는것
// immutable : 객체의 상태를 변경할수 없는것

// #1. int 타입의 객체(변수)는 mutable 합니다.
int n = 10;
n = 20;    // ok


// #2. string 타입의 객체는 immutable 합니다.

string s1 = "abcd";

char c = s1[0]; // ok     읽기는 가능
//s1[0] = 'x';    // error  쓰기는 안됨

// 그래서 string 의 메소드 중에서
// => 자신의 상태를 변경하는 메소드는 없습니다.

string s2 = s1.ToUpper();
                // ToUpper 메소드가 하는 일
                // 1. s1 자체는 변경안됨
                // 2. 대신 s1 의 모든 문자를 대문자로 만든 새로운 문자열반환

Console.WriteLine(s1); // "abcd"
Console.WriteLine(s2); // "ABCD"


// #3. 변수에 담긴 문자열을 변경하려면 어떻게 하나요 ?
// string        : immutable. 변경불가
// StringBuilder : mutable.   변경가능 
//                            좀더 배워야 사용가능. 오후부터 사용


// 참고
// immutable : 변경 불가. 항상 안전하고, 실행속도도 빠릅니다
// => 프로그램에서 변경할일이 없다면,  무조건 immutable 사용
// => "반드시 변경해야 한다" 라고 할때만 mutable 