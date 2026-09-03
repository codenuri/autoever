using static System.Console;



// 방법 #2. 메소드가 실패하면 그냥 프로세스를 종료 하자

// 단점 : 호출자에게 에러를 처리할 기회를 주지 않고, 그냥 종료한다
// => 호출자에게 더좋은 에러 대응 방식이 있을수 있다.
// => 메소드가 실패시 항상 호출자에게 보고해야 한다.

class Database
{
    public Database(string dbname) { }

    public bool Backup()
    {
        // 백업 실패시 아래처럼 프로세스 종료
        Process p = Process.GetCurrentProcess();
        p.Kill();


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
