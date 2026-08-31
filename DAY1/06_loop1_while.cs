using System.ComponentModel;
using static System.Console;

// 핵심 : while loop
// => 파이썬과 동일 개념, 표현법만 약간 다름

int cnt = 0;

while ( cnt < 10 )
{
    WriteLine($"{cnt}");

    ++cnt;
}


cnt = 0;

while (true)        // 무한루프
{
    WriteLine($"{cnt}");

    ++cnt;

    if (cnt == 10)
        break;      // break : 루프 탈출 키워드
                    // continue : 루프의 처음으로 이동
}