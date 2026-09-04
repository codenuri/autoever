using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    public static void Main()
    {
        int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        // 아래 코드의 원리
        // => c 안에 "배열의 참조(복사본아님)" 와 "람다표현식" 만 보관한것
        // => 람다표현식은 아직 실행 안됨. 즉, 조사한것 아님
        var c = arr.Where(n => n % 2 == 1);

        arr[0] = 99;

        // 아래 결과 예측해 보세요. 첫번째 출력이 "1" 일까요 ? "99" 일까요 ?
        foreach (var n in c) // c가 보관한 arr 의 모든 요소를 차례대로
        {                    // c가 보관한 함수에 보내서 true 인 것만 n 으로
                             // 즉, 열거할때 연산되는 것
                             // 지연된 실행 이라고 합니다.
            Console.WriteLine(n);
        }
    }
}
