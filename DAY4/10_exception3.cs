using static System.Console;



// 방법 #3.

// 1. 메소드가 실패하면 호출자에게 보고 한다
//    => 호출자가 던져진 예외를 무시하면 프로그램은 더이상 실행되면 안된다
//    => 종료되어야 한다

class Database
{
    public Database(string dbname) { }

    public bool Backup()
    {
//      if(실패)
            throw new Exception(); // 실패했음을 호출자에게 전달

        return true;
    }

    public void Remove() => WriteLine("Remove DB");
}

class Program
{
    public static void Main()
    {
        Database db = new Database("product.db");

        db.Backup();   // A 

        db.Remove();
    }
}
