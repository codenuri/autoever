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

    public static int HowManyDays(int m) { return days[m - 1]; };
}
class Program
{
    public static void Main()
    {
        // 5월달이 몇일까지 있는지 알고 싶다

        // 다음중 사용하기 편리해 보이는 것은 ?
        // => 기준 날짜가 필요한 작업이 아닙니다.
        // => "5" 라는 월만 알면 됩니다.
        // => static method 가 편리합니다.

        // #1. instance 메소드로 제공
//      Date d = new Date(2026, 5, 1);
//      int ds1 = d.HowManyDays();

        // #2. static 메소드로 제공
        int ds2 = Date.HowManyDays(5);

        //---------------------------------
        // 내일 날짜를 구하고 싶습니다.
        // => 특정 날짜와 연관된 연산입니다
        // => instance method 가 좋습니다.
        // => 복습할때 구현해 보세요 
        Date d3 = new Date(2026, 9, 1);
        Date d4 = d3.Tomorrow();

        // static method 로 하면 아래 처럼해야 합니다.
        // => 좋지 않은 선택
        Date d5 = Date.Tomorrow(2026, 9, 1);

    }
}