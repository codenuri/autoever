using static System.Console;

// 핵심 : for 문

int[] x = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

// C 언어 부터 제공되던 전통적인 형태의 for 문
//      A         B      C
for (int i = 0; i < 10; i++)
{
    WriteLine($"{x[i]}")
}

// 1. A 를 한번 실행
// 2. B 를 조사
//    => true이면 {} 실행후 3번으로
//    => fallse 면 {} 탈출
// 3. C 실행후 2번으로 이동