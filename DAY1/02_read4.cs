using System;

// 핵심 : 입력 버퍼가 아닌 키보드로 부터 직접 입력 받기

Console.Write("press any key >> ");

// 입력에 대한 정확한 원리
// 1. 입력 버퍼에서 읽어서 변수에 담는 것
// 2. 단, 입력 버퍼가 비어 있으면 "사용자 -> 입력 버퍼" 로 담는 과정 필요
//    이 과정을 종료 하려면 enter 필요


// ReadLine : 문자열 입력 - 반환 타입은 string
// Read     : 한문자 입력 - 반환 타입은 int (아스키 코드)
int n = Console.Read();	    // "ABCD" 입력후 enter 해보세요

Console.WriteLine(n);   // 65

n = Console.Read();     // 입력을 대기하지 않고 버퍼에 있던 'B' 꺼내 가기
Console.WriteLine(n);   // 66


// 위 2개 함수는 모두 입력을 종료하기 위해 enter 필요


