class Program
{
    public static void Swap(ref int a, ref int b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    public static void Swap(ref double a, ref double b)
    {
        double tmp = a;
        a = b;
        b = tmp;
    }

    public static void Main()
    {
        int    n1 = 10,  n2 = 20;
        double d1 = 1.1, d2 = 2.3;
                
        Swap(ref n1, ref n2);
        Swap(ref d1, ref d2);
    }
}