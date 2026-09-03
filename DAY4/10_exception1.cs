using static System.Console;

// 함수(메소드)는 실패 할수 있다
// 실패를 어떻게 처리할까 ?

// 방법 #1. 반환값으로 알려주자
// => C 언어의 대표적인 기술

// 단점 
// => 호출자가 반드시 에러를 처리해야하는 것은 아니다
// => 에러를 무시할수 있다 - Main 에서의 A 부분
// => 발생된 에러를 무시하고 계속 실행하면 더큰 문제가 발생할수 있다
// => "DB 백업에 실패했는데, DB 를 삭제!!"

class Database
{
    public Database(string dbname) { }

    public bool Backup()
    {
//      if (실패) return false;

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
