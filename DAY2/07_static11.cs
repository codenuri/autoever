class Date
{
    private int year = 0;
    private int month = 0;
    private int day = 0;

    private static int[] days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


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

    public Date(int y, int m, int d) => (year, month, day) = (y, m, d);

    public Date AddDays(int ds)
    {
        Date temp = new Date(year, month, day + ds); 
        return temp;
    }

    public static int HowManyDays(int m) { return days[m - 1]; }

    public static bool IsLeapYear(int year)
    {
        bool b = (year % 400 == 0) && ((year % 4 == 0) && (year % 100 != 0));
        return b;
    }
    public bool IsLeapYear()
    {
        return Date.IsLeapYear(year); // static method 다시 호출
    }

    // 오늘 날짜를 가지는 Date 객체를 반환하는 정적 메소드
    public static Date TodayM()
    {
        // 여기서는 시스템 내부 함수(OS 가제공하는 함수같은것들)
        // 로 오늘 날짜를 구해야 합니다.
        Date temp = new Date(2026, 9, 1);
        return temp;
    }

    // 오늘날짜를 가진 정적 필드
    public static Date Today = Date.TodayM();
}

class Program
{
    public static void Main()
    {
        // 일반적으로 사용자는 아래 처럼 사용하는 경우는 많지 않습니다.
        Date d1 = new Date(2026, 9, 1);

        // 오늘 날짜 객체가 필요하면 아래 처럼 사용하게 해야 합니다
        // #1 과 #2 중 좋은 것은 ?
        Date today1 = Date.TodayM(); // #1
        Date today2 = Date.Today;   // #2


    }
}