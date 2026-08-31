using static System.Console;

// 제어문
// => C 언어가 현대의 프로그래밍 언어 제어문의 기본 모양을 완성
// => 많은 프로그래밍 언어에 영향을 끼침

// C 언어의 제어문                   C#                   Python
// 조건문 : if,   switch             if, switch           if, match(switch와유사)     
// 반복문 : while, do-while, for     C의 3개 + foreach     while, for(C와 다름, C# foreach)  


// 핵심 : if 문
// => python 과 개념 동일
// => 하지만 표현이 다름
int score = 75;

if ( score > 70)        // C#은 조건문에 () 필요, Python () 없음
{
    // 문장
    // Python : 들여쓰기로 표현
    // C#     : {} 로 표현. {} 안의 문장이 1줄이면 {} 생략가능 - 보통을 표기를 권장
}
else
{
     // 문장
}


