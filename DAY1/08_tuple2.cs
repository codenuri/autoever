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







// #3. Named Member
(int,     int,     int)       v3 = (1,2,3); 


