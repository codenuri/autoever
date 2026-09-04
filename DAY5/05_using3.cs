using Microsoft.VisualBasic.FileIO;
using System;
using System.IO;
using System.Text;

class Program
{
    static void Main()
    {
        // ~ C# 8.0
        // using (....)
        // {
        // }

        // C# 9.0 아래 처럼 가능 - () 아 {} 없어도가능

        using FileStream fs = new FileStream("a.txt", FileMode.Create);
  
        byte[] data = Encoding.UTF8.GetBytes("ABCD");

        fs.Write(data, 0, data.Length);         

    } // <-- fs.Dispose()
}

