class Date
{
    private int year = 0;
    private int month = 0;
    private int day = 0;

    // 날짜 관련 연산을 할때는 월별 날짜수를 알아야 합니다.
    // 핵심 : 아래 배열을 static 으로 설계하는 이유를 알아야 합니다.
    // => 월별 날짜수는 모든 날짜 객체가 공유해도 됩니다.
    // => 객체당 한개의 데이터가 아닌 Date 라는 클래스 자체에 필요한 데이터
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

    // 이제 Date 사용자들이 사용하기 편리하도록 날짜 관련 다양한 메소드제공

    public Date AddDays(int ds)
    {
        Date temp = new Date(year, month, day + ds); // 잘못된 구현

        // 복습시 days 배열을 사용해서 제대로 된 구현을 해보세요
        // => if 등의 제어문을 잘 알아야 합니다.
        // => 윤년도 고려해야 합니다.
            
        return temp;
    }
}
class Program
{
    public static void Main()
    {
        Date d1 = new Date(2026, 9, 1);

        Date d2 = d1.AddDays(1000);

    }
}