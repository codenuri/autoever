using static System.Console;



// 방법 #4. 던져진 예외를 잡는 방법 : try {}  catch ()
// 

class Database
{
    public Database(string dbname) { }

    public bool Backup()
    {
        //      if(실패)
        throw new Exception(); 

        return true;
    }

    public void Remove() => WriteLine("Remove DB");
}

class Program
{
    public static void Main()
    {
        Database db = new Database("product.db");

        // 예외 발생 가능성이 있는 함수(메소드) 호출시 try 블럭안에서 해야 한다
        try
        {
            db.Backup();
        }
        catch(Exception ex)
        {
            Console.WriteLine("예외 발생");
            // 여기서 발생된 문제를 해결할수 없다면
            // 사용자에게 알리고 프로그램을 종료하세요

            // 여기서 종료하지 않으면 프로그램은 계속 실행됩니다.
        }

        db.Remove();
    }
}
