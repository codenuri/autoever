using static System.Console;

// 핵심 : 초기화되지 않은 변수는 쓰기만 가능.
int n;          // 핵심 : n 은 초기값이 없습니다. (쓰레기값 가졌다라고 표현)
int a = 0;

a = n;			// error. n 은 값이 없다 읽을수 없다
WriteLine(n);	// error. 이 코드도 읽는 코드

n = a;	// ok. 쓰는 것은 가능
a = n;  // ok. 위 코드를 통해서 n 은 값을 가지고 있다