using static System.Console;

// #1. construction
int a = 1, b = 2, c = 3;

// 아래 코드는 a, b, c 라는 일반변수를 가지고 tuple 을 만든것
// => tuple construction
var t1 = (a, b, c);



// #2. deconstruction
int x, y, z;

// 아래 코드는 t1이라는 tuple 의 값을 각각, x, y, z 에 담은것
// => tuple 을 분해(deconstruction) 한것
x = t1.Item1;
y = t1.Item2;
z = t1.Item3;

// C# 에서는 위 3줄을 아래 처럼 하면 됩니다.
(x, y, z) = t1; // 위 3줄과 동일

// deconstruction 스타일 
// => 변수 선언후 사용
int a1, a2, a3;
(a1, a2, a3) = t1;


// => 변수 선언 자체를 () 안에
(int b1, int b2, int b3) = t1;






// #3. 아래 2줄의 차이점은 ?
(int a1, int a2, int a3) t2 = (1, 2, 3); 
(int b1, int b2, int b3)    = (4, 5, 6); 

