using static System.Console;

// #1. tuple 생성
int     n = 0; // 일반 변수
int[] arr = { 1, 2, 3 }; // 배열

(int, int, int) t1 = (1, 2, 3); // tuple 을 만드는 정확한 표기법
                                // (int, int, int) 타입

(int, double, string) t2 = (1, 3.4, "hello");

// tuple 의 타입을 직접 표기하면 복잡해 보입니다.
// 그래서 대부분 var 사용
var t3 = (1, 3.4, "hello"); // 위 t2 와 동일합니다.

// 핵심 : tuple 타입 알아 두세요 (int, double, string)
//        강의에서는 대부분 var 사용
//----------------------------------------------

// #2. 요소 접근 : Item1, Item2 ... 사용
var t4 = (1, 2, 3);

t4.Item1 = 20;

WriteLine("{0} {1}", t4.Item1, t4.Item2);
//-------------------------------------------------



// #3. Named Member - 중요!
(int,     int,     int)       t5 = (1, 2, 3); // unnamed tuple 
(int one, int two, int three) t6 = (1, 2, 3); // named tuple

// 요소 접근시
// unnamed tuple : Item1, Item2, ...
// named tuple    : 사용자가 지정한 이름 - 위 코드는 one, two, three

WriteLine($"{t5.Item1}");
WriteLine($"{t6.one}");

// #4. Named Member 를 만드는 2가지 기술
// 1. 타입에 이름 표기
// 2. 초기값에 이름 표기

// 아래 t7, t8 은 완전히 동일
(int one, int two, int three) t7 = (1, 2, 3);

var t8 = (one:1, two:2, three:3);