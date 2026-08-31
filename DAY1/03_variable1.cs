// #0. C# 에서 변수 선언
// Type name = 초기값; // C#
// name = 초기값       // Python

// #1. Data type ( 19 page 참고)
int    n = 0;       // int    : 정수, 4바이트 공간
double d = 3.4;     // double : 실수, 8바이트 공간
char   c = 'A';     // 문자 : ''  
string s = "hello"; // 문자열 : ""
// 파이썬은 '' 와 "" 가 동일. 모두 문자열

// #2. var
// => 데이타 타입을 생략하고 var 키워드로 표기
// => 초기값으로 타입을 추론해 달라는 것
// => C# 에서 널리 사용
var v1 = 10;		// int    v1 = 10
var v2 = 3.4;		// double v2 = 3.4    
var v3 = "hello";	// string v3 = "hello"

// #3. literal
// => Literal : "프로그램 코드에서 직접 표기한 값"
int a1 = 10;	// 10진수	
int a2 = 0x10;	// 16진수	
int a3 = 0b10;	// 2진수	
int a4 = 010;	// 8진수	

// 커다란 리터럴 표기시 읽기 좋게 하기위해 digit separator 사용가능
int a5 = 1000000;	
int a6 = 1_000_000;
int a7 = 1_0_00_00_0;   // ok. 어차피 컴파일 하면 _는 제거 됩니다
                        // 어느 위치에 적어도 상관없지만
                        // 관례대로 10진수는 3자리로 표기하세요


