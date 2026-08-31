using static System.Console;

// while    : 조건을 먼저 조사후 true 이면 실행
// do-while : 먼저 실행후 조건 조사

int cnt = 20;

while (cnt < 10)    // 처음 부터 조건이 false 아래 코드는 한번도 실행안됨
{
    WriteLine($"{cnt}");    
    ++cnt;
}


do
{
    WriteLine($"{cnt}");
    ++cnt;
} while (cnt < 10);    // 한번 실행후 조건 조사

// 언제 사용하나요 ?
// => 사용자에게 3의 배수를 입력 받아야 한다
// => 그런데, 3의 배수가 아니면 제대로 입력 할때까지 다시 입력 받아야 한다

int num;

do
{
    Console.Write("3의 배수 입력 >> ");
    string s = Console.ReadLine();
    num = Convert.ToInt32(s);

} while (num % 3 != 0); // 3의 배수가 아니면 다시 입력