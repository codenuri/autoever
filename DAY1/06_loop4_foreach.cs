using static System.Console;

int[] x = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

// #1. C 언어 부터 제공되던 전통적인 형태의 for 문
for (int i = 0; i < 10; i++)
{
    WriteLine($"{x[i]}")
}

// #2. C# 에서 만든 C 에는 없던 반복문
//       for e in x    <= 파이썬과 동일한 모양
foreach( int e in x )
{
    WriteLine($"{e}")
}
// C#     : while, do-while, for, foreach
// Python : while     X       X   for 
// C++    : while  do-while  for  for 
// Rust   : while,    X       X   for

// 앞으로 예제에서는 조건문과 반복문은 모두 알고 있다는 가정하에 수업