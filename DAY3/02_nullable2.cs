using static System.Console;

// 58 page

// int  : 정수 한개 보관
// int? : 정수 한개 보관 + bool(값 있음/없음 관리)

int n = 0;

// #1. "int? <- int" 의 경우 
// => ok. 58page 그림
int? n1 = n; // ok. 


// #3. int <= int?
int n2 = n1; // error. 값이 없을수도 있다

int n3 = (int)n1; // ok.
                  // 단, n1 == null 이었다면 runtime error

// 안전하게 하려면 n1 이 null 인지 먼저 확인
if ( n1 != null)
{
    int n4 = (int)n1;
}

// 또는 아래 메소드 사용
int n5 = n1.GetValueOrDefault(0);
            // 1. n1 != null 이면 가지고 있던 값 반환
            // 2. n1 == null 이면 0 반환