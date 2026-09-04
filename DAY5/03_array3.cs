using static System.Console;


// 일반적으로 변수에 대해서 어떤 연산을 하고 싶다면
// "변수.메소드()"
// "변수.프라퍼티"
// => 에서 찾으면 됩니다.
int n = 0;
string s = n.ToString();




int[] arr = { 1, 2, 3, 4, 5 };

// #1. 배열 타입 변수는 자체 메소드와 속성이 많지 않습니다
// => 정렬, 뒤집기, 검색 등의 작업은 자체 메소드로 할수 없습니다
// => "Array" 클래스를 사용해야 합니다.
int n = arr.Length; // 5


// #2. 배열에 관한 연산은 "Array 클래스의 static method" 활용
Array.Sort(arr);    // 크기 순서로 다시 정렬 1, 2, 3, 4, 5
Array.Reverse(arr); // 5, 4, 3, 2, 1

foreach(var e in arr)
    Console.WriteLine(e);
