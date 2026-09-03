using static System.Console;

// 메소드는 다양한 이유로 실패할수 있습니다
// 실패의 이유에 대한 정보를 담을수 있도록 별도의 타입을 설계하세요
// => 클래스 이름만으로도 좋은 설명이 됩니다.
// => 이때 Exception 이라는 클래스에서 파생 해야 합니다.

class FileNotFoundException : Exception
{
    public string filename;
    // 이외에도 다양한 정보를 담으세요
}

class NetworkDisconnectException : Exception
{
}

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

        try
        {
            db.Backup();    
            db.Remove();
        }
        catch (Exception ex)
        {
            Console.WriteLine("예외 발생");

        }

    }
}
