using System;

// 핵심 : switch 문
int num = 1;

// switch : 값에 따른 분기문 작성할때 사용

switch( num  )
{
    case 1: 
        Console.WriteLine("one");
        break;          // C 언어는 break 생략가능했지만
                        // C# 은 안됨

    case 2:
        Console.WriteLine("two");
        break;

    default:
        Console.WriteLine("other");
        break;
}


object obj = 3.4;

// C#  switch 는 아주 막강합니다.
// => 패턴 매칭 기능있습니다.

switch(obj)
{
    case 1: break;  // 값조사
            
    case double:    // 타입 조사
        Console.WriteLine("double"); 
        break; 

    // default 는 생략가능
}

