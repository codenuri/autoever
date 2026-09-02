using static System.Console;

// null conditional operator ( ?, ?[]) 

string s1 = "hello";
string s2 = null;

var ret1 = s1.ToString(); // ok. 객체가 존재.
var ret2 = s2.ToString(); // 런타임에러(예외 발생)

// 안전하게 사용하려면 null check 해야 합니다.
// 1. null 이 아닌경우만 메소드 호출
// 2. null 이면 호출 안함
if (s2 != null)
{
    var ret3 = s2.ToString();
}

var ret4 = s2?.ToString(); // 위와 동일
            // 1. s2 != null 이면 s2.ToString() 호출
            // 2. s2 == null 이면 NO operation. null 반환해서 ret4 에대입

// ?? 와 .? 를 헷갈리지 마세요.. 