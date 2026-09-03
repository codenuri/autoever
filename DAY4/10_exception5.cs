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
        //  if(실패)
        throw new FileNotFoundException();
        
        // if (다른이유로 실패)
        throw new NetworkDisconnectException();

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
        catch (FileNotFoundException ex)
        {
            Console.WriteLine("파일 없음 예외 발생");
        }
        catch (NetworkDisconnectException ex)
        {
            Console.WriteLine("네트워크 연결 안됨 예외 발생");
        }
        catch (Exception ex)
        {
            Console.WriteLine("위에서 처리되지 못한 예외");
        }
        
    }
}

// 심각한 오류 : 예외 사용
// 간단한 오류 : 반환값으로 알려주는 경우가 많습니다.

// Rust 언어에는 "예외"가 없습니다.
// => 예외의 단점을 주장하면서
// => 자신만의 오류 처리 방법을 제안합니다
// => 학습할 가치가 있습니다.

// 함수가 실패시 어떻게 처리하는 것이 최선일까 ? 다양한 생각을 해보세요