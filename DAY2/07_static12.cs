class Program
{
    public static void Main()
    {
        // 이미 C# 표준에 날짜 타입이 있습니다.
        // DateTime : 날짜와 시간을 같이 관리

        DateTime dt1 = DateTime.Today; // 오늘 날짜 12:00 으로 초기화
        DateTime dt2 = DateTime.Now;   // 오늘 날짜 현재 시간

        Console.WriteLine(dt2);

        DateTime dt3 = dt2.AddDays(1000);
        Console.WriteLine(dt3);

    }
}