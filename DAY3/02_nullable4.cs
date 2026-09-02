using static System.Console;

// null-coalescing operator (?? 연산자)

int?   n1 = null;

 
//int n2 = n1;    // error

int n3 = n1.GetValueOrDefault(); // ok null 이면 0 반환
int n4 = n1 ?? 0; // 위와 동일
                  // if ( n1 == null )
                  //     return 0;
                  // else
                  //     return n1이가진정수


string s1 = null;
string s2 = s1;

// s1 이 null 이면 "none" 그렇지 않으면 s1 값
// 만들어 보세요
string s3 = s1 ?? "none";

