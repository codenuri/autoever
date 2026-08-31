using static System.Console;

// #1. 함수는 기본 적으로 한개의 값을 반환 합니다.
string Get1()       
{
    return "john";
}

string ret1 = Get1();

// #2. 함수에서 2개 이상 반환 하려면 tuple 사용
(string, int, int) Get2()
{
    return ("john", 20, 180); // 이름, 나이, 키
}

var ret2 = Get2();

WriteLine($"{ret2.Item1}, {ret2.Item2}, {ret2.Item3}"); // john, 20, 180 출력해 보세요


// #3. #2 예제는 Named Member 를 사용하는 것이 좋습니다.
(string name, int age, int height) Get3()
{
    return ("john", 20, 180); 
}

var ret3 = Get3();

WriteLine($"{ret2.name}, {ret2.age}, {ret2.height}");
