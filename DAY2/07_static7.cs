// 07_static7.cpp
// 프로그램에서 "날짜" 를 다루는 경우가 많이 있다
// => Date 타입이 있으면 편리하다

class Date
{
    // #1. 날짜를 만들려면 어떤 데이터가 필요 한가 ? 고민해서 필드를 작성
    private int year = 0;
    private int month = 0;
    private int day = 0;

    // #2. private field 를 사용한 경우 Set/Get 을 위해서 프라퍼티 작성
    // => 복습하실때 Year, Day 도 만들어보세요
    public int Month
    {
        get { return month; }
        set
        {
            if (value < 1 || value > 12)
                throw new Exception();
            month = value;
        }
    }

    // 3. 생성자를 제공해서 필드를 초기화
    public Date(int y, int m, int d) => (year, month, day) = (y, m, d);
}
class Program
{
    public static void Main()
    {
        Date d = new Date(2026, 9, 1);
        d.Month = 9;
    }
}