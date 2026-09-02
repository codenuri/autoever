// 08_ToString1.cs

int n = 0;
double d = 3.4;

// #1. Console.WriteLine() 은 인자로 거의 모든 타입의 객체를 받을수 있습니다.
Console.WriteLine(n);   // 인자로 int 객체 전달
Console.WriteLine(d);   // 인자로 double 객체 전달

// #2. 원리가 뭘까요 ?
void MyWriteLine(object obj)
{
    // obj 의 상태를 문자열로 변경
    string s = obj.ToString();

    // 이제 문자열 s 를 화면에 출력
    Console.WriteLine(s); // 실제는 내부 함수 사용해서 화면에 출력
}
MyWriteLine(n);
MyWriteLine(d);