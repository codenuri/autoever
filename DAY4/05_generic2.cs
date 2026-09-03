class Program
{
    // 아래 Swap 은 메소드가 아닌 "메소드를 만드는 틀" 입니다.
    // 사용법 : Swap<원하는 타입>(ref n1, ref n2)
    // 타입 인자를 받을때 어떤 단어도 가능하지만
    // 관례상 T 를 많이 사용 (Type 이 의미)
    public static void Swap<T>(ref T a, ref T b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }



    public static void Main()
    {
        int n1 = 10, n2 = 20;
        double d1 = 1.1, d2 = 2.3;

        // Generic 을 사용하는 정확한 표기법
        Swap<int>(ref n1, ref n2);      // 1. Swap 틀의 T 를 int 로 변경한 메소드 생성
                                        // 2. 생성된 메소드 호출하는 기계어 코드 생성
        Swap<double>(ref d1, ref d2);

        // Generic 사용시 타입인자 생략 가능
        // => 이 경우 메소드 인자를 보고 컴파일러가 타입 추론
        Swap(ref n1, ref n2); // Swap<int>(ref n1, ref n2);     와 동일
        Swap(ref d1, ref d2); // Swap<double>(ref d1, ref d2);  와 동일
    }
}