using System;
using static System.Console;

// string 특징 - 42 page 그림
// 1. Reference Type
// 2. immutable -> 상태를 변경할수 없다!!
//

string s1 = "AB";
string s2 = s1;

WriteLine($"{s2[0]}"); 

//s2[0] = 'X';    // error

// object.ReferenceEquals(s1, s2) : s1, s2 가 같은 객체를 가리키는지 조사
//                                  => 내일 자세히 배우게 됩니다
WriteLine($"{object.ReferenceEquals(s1, s2)}"); // True

s2 = "XY";  // ok
            // 이코드는 값을 변경하는 것 아닌가요 ?
            // 값 변경이 아닌 새로운 객체 생성 입니다.
            // s2 = new string("XY") 의 의미 입니다.
                

WriteLine($"{object.ReferenceEquals(s1, s2)}"); // False

WriteLine($"{s1} {s2}"); 

