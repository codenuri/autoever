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
        Date temp = new Date(year, month, day + ds); // 잘못된 구현
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
}


class Program
{
    public static void Main()
    {
        // 윤년인지 조사하고 싶습니다.
        // 어떤것이 좋아 보이나요 ?
        // 여러분이 "Date" 설계자라면 #1, #2 중 선택은 ?

        // #1. instance method
        Date d = new Date(2026, 9, 1);
        bool b1 = d.IsLeapYear();

        // #2. static method
        bool b2 = Date.IsLeapYear(2026);


    }
}