int n1 = 10;
int n2 = 20;

// 변수값을 출력하는 방법

// #1. 변수 한개의 값 출력
Console.WriteLine(n1);

// #2. 변수 2개 이상 또는 서식화된 출력
Console.WriteLine("n1 = {0}, n2 = {1}", n1, n2);
Console.WriteLine("n1 = {0}, n2 = {1} {0}", n1, n2);

// #3. 변수 이름은 {} 안에 직접 사용하려면 $"" 사용
// => $"" : 보간 문자열(interpolation string) 이라고 합니다.
Console.WriteLine($"n1 = {n1}, n2 = {n2}");

// 위 문법은 "파이썬과 유사" 합니다.